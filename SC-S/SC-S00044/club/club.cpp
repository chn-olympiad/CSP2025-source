#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long t,n,ans,s,a[3][N],maxa[N],b[N],a1[N],a2[N],a3[N],p[3];
//struct w{
//	int a1,a2,a3,maxa;
//}d[200010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[1][j]>>a[2][j]>>a[3][j];
			p[1]=a[1][j];
			p[2]=a[2][j];
			p[3]=a[3][j];
			sort(p+1,p+3+1);
			a1[j]=p[1];
			a2[j]=p[2];
			a3[j]=p[3];
			if(a3[j]==a[1][j]){
				b[1]++;
			}else if(a3[j]==a[2][j]){
				b[2]++;
			}else{
				b[3]++;
			}
		} 
		
		if(b[1]<=n/2&&b[2]<=n/2&&b[3]<=n/2){
			for(int j=1;j<=n;j++){
				ans+=a3[j];
			}
			cout<<ans<<endl;
			
		}else if(b[1]>n/2){
			sort(a[1]+1,a[1]+n+1);
			for(int j=n;j>=n/2+1;j--){
				ans+=a[1][j];
			}
			for(int j=1;j<=n/2+1;j++){
				ans+=a2[j];
			}
			cout<<ans<<endl;
		}else if(b[2]>n/2){
			sort(a[2]+1,a[2]+n+1);
			for(int j=n;j>=n/2+1;j--){
				ans+=a[2][j];
			}
			for(int j=1;j<=n/2;j++){
				ans+=a2[j];
			}
			cout<<ans<<endl;
		}else if(b[3]>n/2){
			sort(a[3]+1,a[3]+n+1);
			for(int j=n;j>=n/2;j--){
				ans+=a[3][j];
			}
			for(int j=1;j<=n/2;j++){
				ans+=a2[j];
			}
			cout<<ans<<endl;
		}
		ans=0;
		memset(a,0,sizeof(a));
	}
	return 0;
}