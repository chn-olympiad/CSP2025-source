#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k;//11 0|10 1|00 0
int a[500005];

int f[5010][5010];
int d[5010][5010];
int ans=0;
int check(int x){
	if(x==k){
		return 1;
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(check(a[i])){
			f[i][i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			d[i][j]=a[i];
			for(int p=i+1;p<=j;p++){
				d[i][j]^=a[p];
			}
		}
	}
	for(int len=1;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			
			for(int p=i;p<j;p++){
				if(f[i][j]<f[i][p]+f[p+1][j]){
					f[i][j]=f[i][p]+f[p+1][j];
				}
				else if(check(d[i][j])&&f[i][j]<1){
					f[i][j]=1;
				}
			}
		}
	}
	cout<<f[1][n];
	return 0;
}
//4 0
//2 1 0 3

