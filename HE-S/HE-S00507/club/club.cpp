#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	int t,n;
	cin>>t>>n;
	int a[n][3],bm[3];
	for(int k=0;k<=t-1;k++){
		for(int i=0;i<=n-1;i++){
			bm[i]=0;
			for(int j=0;j<=3-1;j++){
				cin>>a[i][j];
			}
		}
	}
	for(int k=0;k<=t-1;k++){
		int sum=0;
		for(int i=0;i<=n-1;i++){
			int maxn=0;
			for(int j=0;j<=3-1;j++){
				maxn=max(a[i][j],maxn);
			}
			for(int h=0;h<=3-1;h++){
				if(maxn==a[i][h]){
					bm[h]++;
					sum+=maxn;
					break;
				} 
			}
		}
		cout<<sum<<endl;
	}
	freopen("club.out","w",stdout);
	return 0;
}
