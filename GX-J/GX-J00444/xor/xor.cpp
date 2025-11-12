#include<iostream>
using namespace std;
int v[501000][300];
int f[501000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,k,a[510000];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			v[i][j]=a[i]^v[i-1][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			f[i]=max(f[i],(v[i][j]==k)+f[j-1]);
		}
	}
	cout<<f[n];
}
