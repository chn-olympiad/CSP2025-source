#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int tmp[1000010];
	int count=1;
	for(unsigned int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			tmp[count++]=a[i]-'0';
		}
	}
	count--;
	sort(tmp+1,tmp+count+1);
	for(int i=count;i>=1;i--)
	{
		cout<<tmp[i];
	}
	return 0;
}
