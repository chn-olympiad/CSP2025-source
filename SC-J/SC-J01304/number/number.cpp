#include<bits/stdc++.h>
using namespace std;
string x;
char y[2000005];
int n=0;
bool cmp(char f,char s)
{
	return f>s;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	for(int i=0;i<=x.size()-1;i=i+1)
	{
		if(x[i]>=48 && x[i]<=57)
		{
			n=n+1;
			y[n]=x[i];
		}
	}
	sort(y+1,y+n+1,cmp);
	for(int i=1;i<=n;i=i+1)
	{
		cout<<y[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}