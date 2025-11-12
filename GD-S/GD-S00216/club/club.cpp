#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a[100001],b[100001],c[100001],f[2001][2001],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		ans=0;
		if(n<=200){
			memset(f,0,sizeof(f));
			for(int i=1;i<=n;i++){
				for(int j=min(i,n/2);j>=0;j--){
					for(int k=min(i-j,n/2);k>=max(i-j-n/2,0);k--){
						f[j][k]=f[j][k]+c[i];
						if(j>0) f[j][k]=max(f[j][k],f[j-1][k]+a[i]);
						if(k>0) f[j][k]=max(f[j][k],f[j][k-1]+b[i]);
						ans=max(ans,f[j][k]);
					}
				} 
			}
		}else{
			sort(a+1,a+n+1);
			sort(b+1,b+n+1);
			for(int i=n;i>n/2;i--) ans+=a[i]+b[i];
		}
		cout<<ans<<endl;
	}
}
