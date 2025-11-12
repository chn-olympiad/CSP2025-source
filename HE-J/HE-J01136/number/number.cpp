#include<bits/stdc++.h>
using namespace std;
int a[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	for(int i=0;i<n.size();i++)
		if(n[i]<='9'&&n[i]>='0')
			a[n[i]-'0']++;
	for(int i=9;i>=0;i--)
	{
		while(1)
		{
			if(a[i]==0)
				break;
			a[i]--;
			cout<<i;
		}
	}
	return 0;
}
