#include<bits/stdc++.h>
using namespace std;
char b[100005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int n=a.size()-1,k=0;
	for(int i=0;i<=n;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[k]=a[i];
			k++;
		}
	}
	int k1=k+1;
	sort(b+0,b+k1,cmp);
	for(int i=0;i<=k;i++)
	{
		cout<<b[i];
	}
	return 0;
}
