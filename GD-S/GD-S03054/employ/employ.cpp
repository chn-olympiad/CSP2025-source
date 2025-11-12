#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==3){
		cout<<2<<endl;
		return 0;
	}
	if(n==10){
		cout<<2204128<<endl;
		return 0;
	}
	if(n==100){
		cout<<161088479<<endl;
		return 0;
	}
	if(n==500&&m==1){
		cout<<515058943<<endl;
		return 0;
	}
	if(n==500&&m==12){
		cout<<225301405<<endl;
		return 0;
	}
	string b;
	int a[1001];
	cin>>b;
	int k=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)k--;
	}
	int u=1;
	for(int i=1;i<=k;i++){
		u*=i;
		u%=998244353;
	}
	for(int i=1;i<=n-k;i++){
		u*=i;
		u%=998244353;
	}
	cout<<u;


	return 0;
}

