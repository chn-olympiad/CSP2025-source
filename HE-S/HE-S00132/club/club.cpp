#include<bits/stdc++.h>
using namespace std;
int main{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,num1=0,num2=0,num3=0,maxn=0,minn=0;
	cin>>t;
	int n;
	cin>>n;
	int a[n][n]={0};
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][i];
		}
	}
	
	for(int j=1;j<=n;j++){
		for(int i=1;i<n;i++){
			maxn=a[i][j]
			if(maxn<a[i+1][j]){
				minn=maxn;
				maxn=a[i+1][j];
				num1+=a[i][j];
			}
			else{
				num2+a[i+1][j];
				continue;
			}
		}	
	}
	if(num1>n/=2){
		num1-minn;
		for(int i=1;i<n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]>a[i][j+2]){
					num1+=a[i][j];	
				}
				else{
					num3+=a[i][j+2];
				}
			}
		}
	}
	else if(num2>n/=2){
		num2-minn;
		for(int i=2;i<n;i++){
			for(int j=1;j<=i;j++){
				if(a[i][j]>a[i][j+1]){
					num2+=a[i][j];	
				}
				else{
					num3+=a[i][j+1];
				}
			}
		}
	}
	else{if(num3>n/=2){
		num-minn;
		for(int i=1;i<n;i++){
			for(int j=1;j<=i;j++){
				if(a[i][j-2]>a[i][j-1]){
					num1+=a[i][j-2];	
				}
				else{
					num2+=a[i][j-1];
				}
			}
		}
	}
	cout<<num1+num2+num3<<endl;
	

	return 0;
}
