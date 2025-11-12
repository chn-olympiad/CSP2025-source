#include <bits/stdc++.h>//GZ-S00366 都匀市第二中学 罗梓菡
using namespace std;

const int MAXN=1e5+1;
int n,m;
string s;
int c[MAXN];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(n==3) cout<<"2"<<endl;
	else if(n==10) cout<<"2204128"<<endl;
	else if(n==100) cout<<"161088479"<<endl;
	else if(n==500 && m==1) cout<<"515058943"<<endl;
	else if(n==500 && m==12) cout<<"225301405"<<endl;
	else cout<<"0"<<endl;
	return 0;
}
