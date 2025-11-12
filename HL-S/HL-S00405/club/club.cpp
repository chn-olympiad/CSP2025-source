#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a[1001][4]={0},ans[1001]={0};
	int b[1001]={0};
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int k=0;k<3;k++){
				cin>>a[j][k];
			}
		}
		for(int j=1;j<=n;j++){//加 
			for(int k=0;k<3;k++){
				if(k==0){
					if(a[j][k]>a[j][k+1]&&a[j][k]>a[j][k+2]){
						b[k]++;
						ans[i]+=a[j][k];
					} 
				}
				if(k==1){
					if(a[j][k]>a[j][k-1]&&a[j][k]>a[j][k+1]){
						b[k]++;
						ans[i]+=a[j][k];
					}
				}
				if(k==2){
					if(a[j][k]>a[j][k-1]&&a[j][k]>a[j][k-2]){
						b[k]++;
						ans[i]+=a[j][k];
					} 
				}
				if(b[k]>n/2){//大于一半 
					if(k==0){
						if(a[j][k+1]>a[j][k]&&a[j][k+1]>a[j][k+2]){
							b[k]--;
							b[k+1]++;
							ans[i]-=a[j][k];
							ans[i]+=a[j][k+1];
						} 
						else if(a[j][k+2]>a[j][k]&&a[j][k+2]>a[j][k+1]){
							b[k]--;
							b[k+2]++;
							ans[i]-=a[j][k];
							ans[i]+=a[j][k+2];
						} 
						else{
							ans[i]-=a[i][k];
							ans[i]+=0;
						}
					}
					if(k==1){
						if(a[j][k-1]>a[j][k]&&a[j][k-1]>a[j][k+1]){
							b[k]--;
							b[k-1]++;
							ans[i]-=a[j][k];
							ans[i]+=a[j][k-1];
						}
						else if(a[j][k+1]>a[j][k]&&a[j][k+1]>a[j][k-1]){
							b[k]--;
							b[k+1]++;
							ans[i]-=a[j][k];
							ans[i]+=a[j][k+1];
						}
						else{
							ans[i]-=a[i][k];
							ans[i]+=0;
						}
					}
					if(k==2){
						if(a[j][k-1]>a[j][k]&&a[j][k-1]>a[j][k-2]){
							b[k]--;
							b[k-1]++;
							ans[i]-=a[j][k];
							ans[i]+=a[j][k-1];
						} 
						else if(a[j][k-2]>a[j][k]&&a[j][k-2]>a[j][k-1]){
							b[k]--;
							b[k-2]++;
							ans[i]-=a[j][k];	
							ans[i]+=a[j][k-2];
						} 
						else{
							ans[i]-=a[i][k];
							ans[i]+=0;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
