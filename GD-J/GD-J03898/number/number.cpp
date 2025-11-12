#include <bits/stdc++.h> 
using namespace std;

string n;
long long num[1000005]={0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int p=0,max;
	cin >> n;
	for(int i=0;i<=n.length()-1;i++)
	{
		if (n[i]>=48 && n[i]<=58) 
		{
			num[p]=int(n[i]-48);
			p +=1;
		}
	}
	
	int a = p;
	for(int i=1;i<a;i++)
	{
		for(int i=p-1;i>=1;i--)
		{
			if (num[i]>num[i-1])
			{
				max = num[i];
				num[i]= num[i-1];
				num[i-1]= max;
			}
			
		}
	}
	for(int i=0;i<p;i++)
	{
		cout << num[i];
	}
	return 0;
}
