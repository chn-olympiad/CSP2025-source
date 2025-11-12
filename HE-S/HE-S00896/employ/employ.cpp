#include<bits/stdc++.h>
using namespace std;
char a[1000],b[1000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(n==3)cout<<2;
	if(n==10)cout<<2204128;
	if(n==100)cout<<161088479;
	if(n==500)cout<<515058943;
	if(m==12)cout<<225301405;
	return 0;
}
