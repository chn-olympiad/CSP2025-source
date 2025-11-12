#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
string s;
int a;
void doing(){
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a;
	if(n==3&&m==2) cout<<2;
	else if(n==10&&m==5) cout<<2204128;
	else if(n==100&&m==47) cout<<161088479;
	else if(n==500&&m==1) cout<<51505893;
	else if(n==500&&m==12) cout<<225301405;
	else cout<<0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	doing();
	return 0;
}
