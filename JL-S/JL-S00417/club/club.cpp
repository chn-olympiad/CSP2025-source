#include<bits/stdc++.h>
using namespace std;
int t;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("clud.out","w",stdout);
	
	cin>>t;
	int n,ans=0;
	int ca[3]={0},num[3]={0};
	for(int z=0;z<t;z++){
		cin>>n;
		int a[n][3],sum[n]={0},mn[n]={0};
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				ca[i]=a[i][j];
			}
			sort(ca,ca+3,cmp);
			sum[i]=ca[0];
			for(int j=0;j<3;j++){
				if(num[j]<n/2){
					mn[i]=sum[i];
					if(sum[i]==a[i][j]){
						num[j]++;
					}
				}
				else{
					mn[i]=a[i][j-1];
				}
			}
		}
		for(int i=0;i<n;i++){
			ans+=mn[i];
		}
		cout<<ans;
	}
	return 0;
}
