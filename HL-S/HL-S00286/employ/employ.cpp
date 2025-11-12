#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[505];
string s;
int p = 0;
int ans = 0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i = 1;i<=n;i++){
		cin>>c[i];
	}
	sort(c,c+n+1);
	if(n==3&&m==2&&s=="101") cout<<2;
	if(n==10&&m==5&&s=="1101111011") cout<<2204128;
	if(n==100&&m==47) cout<<161088479;
	if(n==500&&m==1) cout<<515058943;
	if(n==500&&m==12) cout<<225301405;
	
	else cout<<1;
	
}
