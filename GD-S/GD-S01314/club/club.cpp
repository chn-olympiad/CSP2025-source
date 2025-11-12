#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
using namespace std;

const int N=1e5+5;
int t,n,a[N][3],lmt;
bool gone[3][N];
int cnt[3];
struct Per{
	int d,id,dep;
};
struct cmp{
	bool operator()(Per& a,Per& b){
		if(a.d==b.d){
			return cnt[a.dep]>cnt[b.dep];
		} 
		return a.d>b.d;
	}
};
priority_queue<Per,vector<Per>,cmp> q[3];

void push(int dep,int id,int lstd=4){
	for(int i=0;i<3;++i){
		if(i!=dep and i!=lstd){
			q[dep].push({a[id][dep]-a[id][i],id,i});
		}
	}
	++cnt[dep];
}

bool cmp1(pii& a,pii& b){
	if(a.first==b.first){
		return cnt[a.second]<cnt[b.second];
	}
	return a.first>b.first;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int j=0;j<3;++j){
			for(int i=1;i<=n;++i){
				gone[j][i]=false;
			}
			cnt[j]=0;
		}
		lmt=n/2;
		for(int i=1;i<=n;++i){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		for(int i=1;i<=n;++i){
			pii tmpa[3];
			for(int j=0;j<3;++j){
				tmpa[j].first=a[i][j];
				tmpa[j].second=j;
			}
			sort(tmpa,tmpa+3,greater<pii>());
			for(int j=0;j<3;++j){
				while(not q[j].empty() and gone[j][q[j].top().id]) q[j].pop();
			}
			bool f=true;
			for(int j=0;j<3;++j){
				int qid=tmpa[j].second;
				if(cnt[qid]<lmt){
					push(qid,i);
					f=false;
					break;
				}else{
					Per tp=q[qid].top();
					if(cnt[tp.dep]<lmt and tp.d<tmpa[j].first){
						q[qid].pop();
						--cnt[qid];
						gone[qid][tp.id]=true;
						push(tp.dep,tp.id,qid);
						push(qid,i);
						f=false;
						break;
					}
				}
			}
			if(f){
				for(int j=0;j<3;++j){
					int qid=tmpa[j].second;
					if(cnt[qid]<lmt){
						push(qid,i);
						break;
					}
				}
			}
		}
		ll ans=0;
		for(int i=0;i<3;++i){
			while(not q[i].empty()){
				Per tp=q[i].top();
				if(not gone[i][tp.id]){
					ans+=a[tp.id][i];
					gone[i][tp.id]=true;
				}
				q[i].pop();
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

