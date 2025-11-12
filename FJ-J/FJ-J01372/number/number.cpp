#include<bits/stdc++.h>
using namespace std;
string a;
int sum[100010],j;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if('0'<=a[i]&&a[i]<='9')
			sum[++j]=a[i]-'0';
	}
	sort(sum+1,sum+j+1,cmp);
	bool f=false;
	//cout<<j<<'\n';
	for(int i=1;i<=j;i++)
	{
		if(sum[i]==0&&!f)
			continue;
		cout<<sum[i];
		f=true;
	}
	if(!f)
	{
		cout<<0;
	}
	return 0;
}
