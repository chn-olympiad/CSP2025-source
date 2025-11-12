#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int t,n,a[100005][3],ans,h[3],A[100005],B[100005],C[100005],ret;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		h[0]=h[1]=h[2]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				ans+=a[i][0];
				h[0]++;
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				ans+=a[i][1];
				h[1]++;
			}
			else{
				ans+=a[i][2];
				h[2]++;
			}
		}
		if(h[0]<=(n/2)&&h[1]<=(n/2)&&h[2]<=(n/2)){
			cout<<ans<<endl;
			continue;
		}
		ans=0;
		for(int i=0;i<=2;i++){
			ret=0;
			for(int j=1;j<=n;j++){
				A[j]=a[j][i];
				B[j]=0;
				for(int k=0;k<=2;k++){
					if(k==i){
						continue;
					}
					B[j]=max(B[j],a[j][k]);
				}
				C[j]=A[j]-B[j];
			}
			sort(C+1,C+n+1);
			for(int j=1;j<=n;j++){
				ret+=B[j];
			}
			for(int j=(n/2)+1;j<=n;j++){
				ret+=C[j];
			}
			ans=max(ans,ret);
		}
		cout<<ans<<endl;
	}
	return 0;
}
