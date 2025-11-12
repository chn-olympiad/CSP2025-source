//GZ-S00104 贵阳市南明区双龙华麟学校 周子铠 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10; 
int n,t,a[N][4],mmax[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(mmax,0,sizeof(mmax));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				mmax[i]=max(mmax[i],a[i][j]);
			}
		}
		if(n==2){
			int sum=0;
			for(int i=1;i<=n;i++){
				sum+=mmax[i];
			}
			cout<<sum<<endl;
			continue;
		}
		int sum=0,b[N];
		for(int i=1;i<=n;i++){
			b[i]=mmax[i];
		}
		sort(b+1,b+n+1);
		for(int i=1;i<=n/2;i++){
			sum+=b[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
