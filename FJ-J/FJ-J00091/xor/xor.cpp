#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,k;
int cnt=0;
int a[MAXN];
int x[MAXN];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		x[i]=x[i-1]^a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int t=x[i]^a[i];
		for(int j=i;j<=n;j++)
		{
			if(x[j]==t)
			{
				cnt++;
				break;
			}
		}
	}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
