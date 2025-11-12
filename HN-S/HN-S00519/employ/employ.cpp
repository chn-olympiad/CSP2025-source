#include<bits/stdc++.h>
using namespace std;
int n,m,s[510],d[510],e[510][2],tot,now;
void asd(int w)
{
	if (w>m)
	{
		if (now>=m)
		{
			tot++;
			tot=tot%998244353;
		}
		return;
	}
	for (int i=1;i<=n;i++)
	{
	    if (e[i][1]!=0)
	        continue;
		if (e[i][0]>d[w]&&s[i]==1)
		    now++;
		e[i][1]=1;
		asd(w+1);
		e[i][1]=0;
		if (e[i][0]>d[w]&&s[i]==1)
		    now--;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for (int i=n;i>0;i--)
	{
		char a;
		cin>>a;
		s[i]=a-48;
	}
	for (int i=1;i<=n;i++)
	{
		cin>>e[i][0];
		d[i]=d[i-1]+s[i];
	}
	asd(1);
	cout<<tot;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
