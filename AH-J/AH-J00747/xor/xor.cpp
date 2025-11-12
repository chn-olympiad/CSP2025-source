#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
const int F=5e3+5;
ll n,k;
ll a[N];
ll pxor[N];//异或前缀和
int c;
//01背包+降维 但是我不会
int f[F][F];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pxor[i]=(pxor[i-1]^a[i]);
	}
	for(int l=1;l<=n;l++){
		for(int r=1;r<=n;r++){
			int x=(pxor[r]^pxor[l-1]);
			if(x==k){
				/*
				for(int i=1;i<l;i++){
					for(int j=1;j<l;j++){
						f[l][r]=max(f[l-1][r-1],f[i][j]+1);
					}
				}
				*/
				c++;
			}
		}
	}
	cout<<c;
	//cout<<f[n][n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
