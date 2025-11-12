#include <bits/stdc++.h>
using namespace std;
int i,j;
int a[1000][1000];
int sum=0;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	cin>>sum;
	string s1,s2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=q;j++)
		{
			cin>>s1>>s2;
			if(s1=='a'&&s2=='b'&&s1=='b'&&s2=='a')
			{
				swap(s1,s2);
				sum++;
			}
		}
	}
	cout<<sum<<endl;
}