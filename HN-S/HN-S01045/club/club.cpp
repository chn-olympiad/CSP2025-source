#include<bits/stdc++.h>
using namespace std;
long long a[100005][4];
long long b[100005];
long long a2[100005][4];
long long maxn[100005];	
long long cmaxn[100005];
long long t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;	
		for(int i=1;i<=n;i++){
			maxn[i]=-10000;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];	
				maxn[i]=max(a[i][j],maxn[i]);
			}
			for(int j=1;j<=n;j++)
				for(int k=1;k<=3;k++)
					a2[j][k]=a[j][k];
			
			for(int k=1;k<=3;k++)
				if(a2[i][k]==maxn[i])
					a2[i][k]==-1;
			cmaxn[i]=-10000;
			for(int j=1;j<=3;j++)
				cmaxn[i]=max(cmaxn[i],a2[i][j]);
			for(int k=1;k<=3;k++){
				if(a[i][k]==maxn[i]){
					b[k]+=1;
				}
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){	
			for(int j=1;j<=3;j++){
				if(b[j]>(n/2)){
					sum+=cmaxn[i];	
				}
			}
			sum+=maxn[i];

		}
		cout<<sum<<' ';
	}
	return 0;
} 
