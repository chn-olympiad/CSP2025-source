#include<bits/stdc++.h>
using namespace std;
int T;
long long a[100005],b[100005],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n,ans=0;
		int mx=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cin>>n;
		if(n==2){
			for(int i=1;i<=n;i++){
				cin>>a[i]>>b[i]>>c[i];
			}
			int A[12];
			A[1]=a[1]+b[2];
			A[2]=a[1]+c[2];
			A[3]=b[1]+a[2];
			A[4]=b[1]+c[2];
			A[5]=c[1]+a[2];
			A[6]=c[1]+b[2];
			for(int i=1;i<=6;i++){
				mx=max(mx,A[i]);
			}
			cout<<mx<<'\n';
		}
		else{
			int hu[100005];
			for(int i=1;i<=n;i++){
				cin>>a[i]>>b[i]>>c[i];
				int mx=max(a[i],max(b[i],c[i]));
				ans+=mx;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}