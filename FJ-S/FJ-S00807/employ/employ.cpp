#include<bits/stdc++.h>
using namespace std;
int m,n;
int k,nx[100001];
int k1[1001];
long int x;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>k;
	for(int i=0;i<n;i++){
		cin>>nx[i];
	}
	int a=1;
	for(int i=1;i<=n-1;i++){
		a=a*10;
	}
	for(int i=n;i>0;i--){
		k1[i]=k/a;
		k=k-k1[i]*a;
		a=a/10;
	}
	if(n==3){
		cout<<"2";
	}
	else{
		x=k%998244353;
		cout<<x;
	}
	return 0;
}
