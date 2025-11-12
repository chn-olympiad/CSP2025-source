#include<bits/stdc++.h> 
using namespace std;
int sum,n,m;
int a[10000][10000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	int b[n+1];
	for(int i=1;i<=n;i++){
		cin>>b[i];
		a[i][i]=b[i]^b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i][j]==0){
				a[i][j]=a[i][j-1]^b[j];
			}
		}
	}
	for(int i=1;i<=n;i++){	
		for(int j=i;j<=n;j++){
			if(a[i][j]==m){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
} 
