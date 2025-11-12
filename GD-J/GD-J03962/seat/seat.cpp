#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110],s[110],mp[110][110];
int sum;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){//输入 v
		cin>>a[i];
		if(i==1){
			sum=a[i];
		}
	}
	int maxn=0,z=0;
	for(int i=1;i<=n*m;i++){//排序 v
		for(int j=1;j<=n*m;j++){
			if(maxn<a[j]){
				maxn=a[j];
				z=j;
			}
		}
		maxn=0;
		s[i]=a[z];
		a[z]=0;
	}
	for(int k=1;k<=n*m;k++){
		for(int i=1;i<=m;i++){//排序到地图中 v
			if(i%2!=0){
				for(int j=1;j<=n;j++) mp[i][j]=s[k];
			}
			else{
				for(int j=n;j>=1;j--) mp[i][j]=s[k];
			}
		}
	}
	
	for(int i=1;i<=m;i++){//查找 
			if(i%2!=0){
				for(int j=1;j<=n;j++){
					if(rsum==mp[i][j]){
						cout<<i<<" "<<j<<" ";
						return 0;
					}
				}
			}
			else{
				for(int j=n-1;j>=1;j--){
					if(rsum==mp[i][j]){
						cout<<i<<" "<<j<<" ";
						return 0;
					}
				}
			}
	}
	
	return 0;
}
