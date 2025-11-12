#include<bits/stdc++.h>
#define ff(i,n) for(int i=1;i<=n;i++)
#define rep(i,s,n) for(int i=s;i<=n;i++)
#define int long long
using namespace std;
const int N=400+10,mod=1e9+7;
int i,j,n,m,k,x,y,tot,z;
int f[N][N],s[N][3];
main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		memset(f,0,sizeof f);
		bool p=0;
		ff(i,n){
			cin>>s[i][0]>>s[i][1]>>s[i][2];
			if(s[i][1]||s[i][2])p=1;
		}
		if(!p){
			priority_queue<int>q;
			ff(i,n)q.push(s[i][0]);
			int ans=0,c=n/2;
			while(c--)ans+=q.top(),q.pop();
			cout<<ans<<'\n';
			continue;
		}
		ff(i,n){
			int lim=min(n/2,i);
			for(int a=lim;a>=0;a--){
				for(int b=lim;b>=0;b--){
					int c=i-a-b;
					if(max(a,max(b,c))>n/2)continue;
					if(c<=n/2)f[a][b]+=s[i][2];
					if(a)f[a][b]=max(f[a][b],f[a-1][b]+s[i][0]);
					if(b)f[a][b]=max(f[a][b],f[a][b-1]+s[i][1]);
				}
			}
		}
		int ans=0;
		rep(a,0,n/2){
			rep(b,0,n/2){
				if(n-a-b<=n/2)ans=max(ans,f[a][b]);
			}
		}
		cout<<ans<<'\n';
	}
}
