#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read() {
	ll e=1,v=0;
	char s=getchar();
	while(s<'0'||s>'9') {
		if(s=='-') {
			e=-1;
			s=getchar();
			break;
		} else s=getchar();
	}
	while(s>='0'&&s<='9') {
		v=(v<<3)+(v<<1)+s-'0';
		s=getchar();
	}
	return e*v;
}
ll t,n,m,a[100001][4],ans,f[201][101][101],biao,diao,q[100001],sb[100001],nm[100001];
inline void dfs(ll x,ll y,ll e,ll s,ll sum) {
	if(x==n+1&&sum>=ans)ans=sum;
	else {
		if(y<n/2)dfs(x+1,y+1,e,s,sum+a[x][1]);
		if(e<n/2)dfs(x+1,y,e+1,s,sum+a[x][2]);
		if(s<n/2)dfs(x+1,y,e,s+1,sum+a[x][3]);
	}
	return;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	for(int iii=1; iii<=t; iii++) {
		n=read();
		ans=0;
		for(int i=1; i<=n; i++) {
			a[i][1]=read();
			q[i]=a[i][1];
			a[i][2]=read();
			sb[i]=abs(a[i][2]-a[i][1]);
			nm[i]=i;
			a[i][3]=read();
		}
		for(int i=1; i<=n; i++) {
			if(a[i][3]!=0)biao=1;
		}
		for(int i=1; i<=n; i++) {
			if(a[i][2]!=0)diao=1;
		}
		/*	if(n<=30) {
				dfs(1,0,0,0,0);
			} else
			*/ {
			if(diao==0&&biao==0) {
				sort(q+1,q+1+n);
				for(int i=n; i>=n/2; i--) {
					ans=ans+q[i];
				}
			} else if(biao==0) {
				ans=0;
				for(int i=1; i<=n; i++) {
					for(int j=i+1; j<=n; j++) {
						if(sb[j]<sb[i]) {
							int y;
							y=sb[i];
							sb[i]=sb[j];
							sb[j]=y;
							y=nm[i];
							nm[i]=nm[j];
							nm[j]=y;
						}
					}
				}
				//for(int i=1; i<=n; i++) cout<<nm[i]<<" ";
				for(int i=1; i<=n/2; i++) {
					ans=ans+min(a[nm[i]][1],a[nm[i]][2]);
				}
				for(int i=n/2+1; i<=n; i++) {
					ans=ans+max(a[nm[i]][1],a[nm[i]][2]);
				}
			}
		}
		cout<<ans<<endl;
	}


	return 0;
}
//1 4 20 3 0 21 2 0 24 0 0 29 10 0
