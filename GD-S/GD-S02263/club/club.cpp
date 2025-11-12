#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,pair<int,int> >
#define ll long long
const int N=1e5+10;
int T,n;
int val[N][4];
int opt[N],cnt[4];
int idx;
priority_queue<pii> q;

int cal(int u,int v){
	if(v==1)return u==1?3:u-1;
	else return u==3?1:u+1;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		for(int i=1;i<=3;i++)cnt[i]=0;
		idx=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>val[i][1]>>val[i][2]>>val[i][3];
			if(val[i][1]>val[i][2]&&val[i][1]>val[i][3])opt[i]=1;
			else if(val[i][2]>val[i][3])opt[i]=2;
			else opt[i]=3;
		}
		for(int i=1;i<=n;i++){
			cnt[opt[i]]++;
			if(cnt[opt[i]]>n/2)idx=opt[i];
		}
		if(idx){
			for(int i=1;i<=n;i++){
				if(opt[i]==idx){
					int _up=val[i][cal(idx,1)];
					int _down=val[i][cal(idx,2)];
					if(_up>_down)q.push({ _up-val[i][idx],{1,i} });
					else q.push({ _down-val[i][idx],{2,i} });
				}
			}
			while(cnt[idx]>n/2){
				pii u=q.top();
				q.pop();
				cnt[idx]--;
				if(u.second.first==1)opt[u.second.second]=cal(idx,1);
				else opt[u.second.second]=cal(idx,2);
			}
			while(q.size())q.pop();
		}
		ll ans=0;
		for(int i=1;i<=n;i++)ans+=val[i][opt[i]];
		cout<<ans<<endl;
	}
	return 0;
} 
