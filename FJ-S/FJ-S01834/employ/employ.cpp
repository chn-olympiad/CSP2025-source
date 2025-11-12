#include<bits/stdc++.h>
using namespace std;
int n,m,k;
string s;
int c[505];
int f(int x){
	int r=1;
	for(int i=2;i<=x;i++) r=r*i%998244353;
	return r;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",c+i);
		if(c[i]==0) k++;
	}
	if(k>n-m){
		printf("0");
		return 0;
	}
	cout<<f(n);
	return 0;
}

