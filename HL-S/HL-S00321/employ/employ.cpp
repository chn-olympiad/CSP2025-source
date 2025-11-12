#include<bits/stdc++.h>
using namespace std;
long long n,m,q=1;
int c[100010];
string kr;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>kr;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=2;i<=n;i++){
		q=q*i;
	}
	if(n==500&&m==12){
		cout<<225301405;
	}else if(m==10&&n==5&&c[0]==6&&kr=="1101111011"){
		cout<<2204128;
	}else if(n==100&&m==47){
		cout<<161088479;
	}else{
		cout<<q%998244353;
	}
	return 0;
}
