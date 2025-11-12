#include<bits/stdc++.h>
#define ll long long
using namespace std;
char o[1000001];
ll p[100001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>o;
	int u=strlen(o),cnt=0;
	for(int i=0;i<=u;i++)
	{
		if(o[i]>='0' && o[i]<='9') p[++cnt]=o[i]-'0';
	}
	sort(p+1,p+1+cnt);
	for(int i=cnt;i>=1;i--)
	{
		cout<<p[i];
	}
	return 0;
}	
