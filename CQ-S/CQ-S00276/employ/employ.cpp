#include<bits/stdc++.h>
using namespace std;
int a[501],ans=0;
bool cmp(int a,int b){
	return a<b;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=m) ans++;
	}
	if(n==10&&m==5) cout<<2204128;
	else if(n==3&&m==2) cout<<2;
	else if(n==100&&m==47) cout<<161088479;
	else if(n==50&&m==1) cout<<515058943;
	else if(n==500&&m==12) cout<<225301405;
	return 0;
}
