#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[10000000],a[10000000];
int main()
{
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdin);
	string s;
	cin>>n>>m>>s;
	int sum=0,num=0;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		if(s[i]==1&&num<c[i])
		{
			a[i]=1;
			sum++;
		}
		if(s[i]==0||num>=c[i])
		{
			a[i]=0;
			num++;
		}
	}
	cout<<num;
	fclose(stdin);
    fclose(stdout);
}
