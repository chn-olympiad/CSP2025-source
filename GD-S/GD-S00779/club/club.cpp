#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N=1e5+5; 

struct Node{
	int a1,a2;
}p[N];

int T,n,m;
int a[N][4];
long long f[35][35][35][35];
long long ans=0;

bool cmp(Node a,Node b){
	return max(a.a1,a.a2)>max(b.a1,b.a2);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) cin>>a[i][j];
		} 
		ans=0;
		if(n<=30){
			memset(f,0,sizeof(f));
			for(int i=1;i<=n;i++){
				for(int c1=0;c1<=min(i,n/2);c1++){
					for(int c2=0;c2<=min(i-c1,n/2);c2++){
						int c3=i-c1-c2;
						if(c3>n/2) continue;
						if(c1>0) f[i][c1][c2][c3]=max(f[i][c1][c2][c3],f[i-1][c1-1][c2][c3]+a[i][1]);
						if(c2>0) f[i][c1][c2][c3]=max(f[i][c1][c2][c3],f[i-1][c1][c2-1][c3]+a[i][2]);
						if(c3>0) f[i][c1][c2][c3]=max(f[i][c1][c2][c3],f[i-1][c1][c2][c3-1]+a[i][3]);						
						//f[i][c1][c2][c3]=max(max(f[i-1][c1-1][c2][c3]+a[i][1],f[i-1][c1][c2-1][c3]+a[i][2]),f[i-1][c1][c2][c3-1]+a[i][3]);
					}
				}
			}
			for(int c1=0;c1<=n/2;c1++){
				for(int c2=0;c2<=n/2;c2++){
					int c3=n-c1-c2;
					if(c3>n/2) continue;
					ans=max(ans,f[n][c1][c2][c3]);
				}
			}
			cout<<ans<<endl;continue;
		}
		for(int i=1;i<=n;i++) p[i]={a[i][1],a[i][2]};
		sort(p+1,p+n+1,cmp);
		int l=0,r=0;
		for(int i=1;i<=n;i++){
			if(p[i].a1>p[i].a2){
				if(l<n/2) l++,ans+=p[i].a1;
				else r++,ans+=p[i].a2;
			} 
			else{
				if(r<n/2) r++,ans+=p[i].a2;
				else l++,ans+=p[i].a1;				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
 
