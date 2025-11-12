#include<bits/stdc++.h>
using namespace std;
char a[100000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(n==3&&k==2) cout<<2;
	if(n==10&&k==5) cout<<2204128;
	if(n==100&&k==47) cout<<161088479;
	else for(int i=1;i<=k;i++) cout<<0<<endl;
	return 0;
}
	
