#include<bits/stdc++.h>
using namespace std;
//Òì»òÊÇ'^' 
int n;
long long k;
long long a[500005];
long long as[500005][500005];
long long tool;
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//Çî¾Ù
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			tool=a[i];
			for(int m=i+1;m<=j;m++){
				tool=tool^a[m];
			}
			as[i][j]=tool;
		}
	}
	cout<<as[2][4];
	return 0;
}
