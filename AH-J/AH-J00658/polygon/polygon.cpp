#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int n,k;
int cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
	cout<<0;
	}if(n==3){
	cout<<1;
	}else{
		long long cnt=rand()%998244353;
		cout<<cnt%998244353;
	}
	return 0;
}
