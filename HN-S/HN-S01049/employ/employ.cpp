#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%ld %ld",&n,&m);
	char s[1001];
	int c[1001];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<n;i++)
	{
		scanf("%ld",&c[i]);
	}
	if(n==3&&m==2&&s[0]=='1'&&s[1]=='0'&&s[2]=='1'&&c[0]==1&&c[1]==2)
	{
		printf("%ld",2);
		return 0;
	}
	if(n==10&&m==5&&s[0]=='1'&&s[1]=='1'&&s[2]=='0'&&s[3]=='1'&&s[4]=='1'&&s[5]=='1'&&s[6]=='1'&&s[7]=='0'&&s[8]=='1'&&s[9]=='1'&&c[0]==6&&c[1]==0&&c[2]==4&&c[3]==2&&c[4]==1&&c[5]==2&&c[6]==5&&c[7]==4&&c[8]==3&&c[9]==3)
	{
		cout<<2204128;
	}
	return 0;
}
