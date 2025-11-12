#include<bits/stdc++.h>
using namespace std;
long long a[100001][4],c[4][100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int k1,k2,k3;
		long long ans=0;
		k1=k2=k3=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) cin>>a[i][j];
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
				c[1][++k1]=a[i][1]-max(a[i][2],a[i][3]);
			}else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
				c[2][++k2]=a[i][2]-max(a[i][1],a[i][3]);
			}else{
				c[3][++k3]=a[i][3]-max(a[i][1],a[i][2]);
			}
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		sort(c[1]+1,c[1]+k1+1);
		sort(c[2]+1,c[2]+k2+1);
		sort(c[3]+1,c[3]+k3+1);
		if(k1>n/2){
			for(int i=1;i<=k1-n/2;i++) ans-=c[1][i];
		}else if(k2>n/2){
			for(int i=1;i<=k2-n/2;i++) ans-=c[2][i];
		}else if(k3>n/2){
			for(int i=1;i<=k3-n/2;i++) ans-=c[3][i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
