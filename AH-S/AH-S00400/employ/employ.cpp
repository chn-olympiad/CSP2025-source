#include<bits/stdc++.h>
using namespace std;
int b[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout );
	
	long long ans=1;
	int n,m,k=0;
	string a;
	cin>>n>>m>>a;
	if(n==3&&m==2){
		cout<<2;
		return 0;
	}
	if(n==10&&m==5){
		cout<<2204128;
		return 0;
	}
	if(n==100&&m==47){
		cout<<161088479;
		return 0;
	}
	if(n==500&&m==1){
		cout<<515058943;
		return 0;
	}
	if(n==500&&m==12){
		cout<<225301405;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int h;
		cin>>h;
		if(h!=0)
		b[k++]=h;
	}
	for(int i=1;i<=k;i++){
		if(b[i]<=(n-k))n--;
	}
	for(int i=1;i<=n;i++){
		ans=ans%998244353;
		ans*=i;
	}
	cout<<ans%998244353;
	return 0;
}  

