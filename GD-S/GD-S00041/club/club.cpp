#include<iostream>
#include<queue>
#include<utility>
using namespace std;
const int N=1e5+10;
using pii=pair<int,int>;
priority_queue<int> q;
int n,tmx,cnt[3],res;
pii mx[N],m2x[N],buf;
void run(){
	cin>>n;
	cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=1;i<=n;i++){
		mx[i]=m2x[i]={0,0};
		for(int j=0;j<3;j++){
			cin>>buf.first;
			buf.second=j;
			if(mx[i]<=buf)m2x[i]=mx[i],mx[i]=buf;
			else if(m2x[i]<=buf)m2x[i]=buf;
		}
	}
	res=0;
	for(int i=1;i<=n;i++){
		cnt[mx[i].second]++;
		res+=mx[i].first;
	}
	tmx=max(max(cnt[0],cnt[1]),cnt[2]);
	if(tmx*2<=n){
		cout<<res<<'\n';
		return;
	}
	while(q.size())q.pop();
	for(int i=1;i<=n;i++){
		if(cnt[mx[i].second]==tmx)q.emplace(m2x[i].first-mx[i].first);
	}
	while(tmx*2>n){
		tmx--;
		res+=q.top();
		q.pop();
	}
	cout<<res<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)run();
}