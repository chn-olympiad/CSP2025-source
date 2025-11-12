#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a;
	cin>>a;
	int a1=a/1%10;
	int a2=a/10%10;
	int a3=a/100%10;
	int a4=a/1000%10;
	int a5=a/10000%10;
	int a6=a/100000%10;
	int a7=a/1000000%10;
	int a8=a/10000000%10;
	int a9=a/100000000%10;
	if(a1||a2||a3||a4||a5||a6||a7||a8||a9==9) cout<<9;
	if(a1||a2||a3||a4||a5||a6||a7||a8||a9==8) cout<<8;
	if(a1||a2||a3||a4||a5||a6||a7||a8||a9==7) cout<<7;
	if(a1||a2||a3||a4||a5||a6||a7||a8||a9==6) cout<<6;
	if(a1||a2||a3||a4||a5||a6||a7||a8||a9==5) cout<<5;
	if(a1||a2||a3||a4||a5||a6||a7||a8||a9==4) cout<<4;
	if(a1||a2||a3||a4||a5||a6||a7||a8||a9==3) cout<<3;
	if(a1||a2||a3||a4||a5||a6||a7||a8||a9==2) cout<<2;
	if(a1||a2||a3||a4||a5||a6||a7||a8||a9==1) cout<<1;
	return 0;
}
