#include<bits/stdc++.h>
#define int long long
using namespace std;
int bucket[10];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int cnt=0;
	for(int i=0;i<a.size();i++)
	{
		if('0'<=a[i]&&a[i]<='9')
		{
			bucket[a[i]-'0']++;
		}
	}
	bool flag=false;
	for(int i=9;i>=0;i--)
	{
		while(bucket[i])
		{
			if(i!=0)flag=true;
			if(flag)
			{
				cout<<i;
				bucket[i]--;
			}
			else 
			{
				cout<<0;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
