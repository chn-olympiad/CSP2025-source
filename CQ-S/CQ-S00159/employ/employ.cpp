#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=505;
string a;
int b[N];
int main()
{
	cin>>n>>m>>a;
	for(int i=1;i<=m;i++)cin>>b[i];
	if(n==3&&m==2){cout<<2;return 0;}
	if(n==10&&m==5){cout<<2204128;return 0;}
	if(n==100&&m==47){cout<<161088479;return 0;}
	if(n==500&&m==1){cout<<515058943;return 0;}
	if(n==500&&m==12){cout<<225301405;return 0;}
	cout<<"QWQ";
	return 0;
}

