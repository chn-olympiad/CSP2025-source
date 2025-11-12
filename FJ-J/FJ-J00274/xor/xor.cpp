#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,l=0;
	cin>>n>>k;
	int a[n+5][n+5];
	for(int i=1;i<=n;i++){
		cin>>a[1][i];
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n-pow(2,i-1);j++){
			a[i][j]=a[i-1][j]^a[i-1][j+pow(2,i-1)];
			if(a[i][j]==k)l++;
		}
	}
	cout<<l;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
