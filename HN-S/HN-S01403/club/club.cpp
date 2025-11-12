#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int t,n,a[N][4];
int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		int ans=0;
		queue<int>q[4];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
			a[i][j]=read();
			int mx=0;
			for(int j=1;j<=3;j++)
			if(a[i][j]>=a[i][mx])
			mx=j;
			q[mx].push(i);
			ans+=a[i][mx];
		}
		int mx=0;
		for(int j=1;j<=3;j++)
		if(q[j].size()>=q[mx].size())
		mx=j;
		int sz=q[mx].size();
		priority_queue<int,vector<int>,greater<int> >p;
		while(!q[mx].empty()){
			 int i=q[mx].front();
			 q[mx].pop();
			 int mi=1e9;
			 for(int j=1;j<=3;j++)
			 if(mx!=j)mi=min(mi,a[i][mx]-a[i][j]);
			 p.push(mi);
		}
		for(int i=1;i<=sz-n/2;i++){
			ans-=p.top();
			p.pop();
		}
		cout<<ans<<endl;
	}
	return 0;
}
