#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int x[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,s=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	for(int i=1;i<=n;i++)
	{
		int t=x[i];
		if(t==m)
		{
			s++;
			continue;
		}
		for(int j=i+1;j<=n;j++)
		{
			if(x[j]==m)
			{
				s++;
				i=j;
				break;
			}
			t^=x[j];
			if(t==m)
			{
				s++;
				i=j;
				break;
			}
		}
	}
	cout<<s;
	fclose(stdin);fclose(stdout);
	return 0;
}
