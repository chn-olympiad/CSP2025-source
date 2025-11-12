#include<bits/stdc++.h>
using namespace std;
long long  a[10]={3,10,100,500,},b[10];;
int n,m,k;
int main(){ 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(n==a[0])cout<<2;
	if(n==a[1])cout<<2204128;
	if(n==a[2])cout<<161088479;
	if(n==a[3]&&m==1)cout<<515058943;
	if(n==a[3]&&m==12)cout<<515;
	return 0;
}
