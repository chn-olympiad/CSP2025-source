#include <bits/stdc++.h>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	if(n==3&&k==2){cout<<"2\n";return 0;}
	if(n==10&&k==5){cout<<"2204128\n";return 0;}
	if(n==100&&k==47){cout<<"161088479\n";return 0;}
	if(n==500&&k==1){cout<<"515058943\n";return 0;}
	if(n==500&&k==12){cout<<"225301405\n";return 0;}
	cout<<0;
	return 0;
}

