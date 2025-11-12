#include <bits/stdc++.h>
using namespace std;
int n,a[10000],ans;
bool b[10000];
void sou(int s,int bs,int m,int l)
{
	for(int i=l+1;i<=n;i++)
	{
		if(b[i])
			continue;
		b[i]=true;
		if(s>bs*2&&m>=3)
		{
			ans++;
//			printf("S%d,Bs%d,M%d,L%d",s,bs,m,i);
		}
		sou(s+a[i],max(bs,a[i]),m+1,i);
		b[i]=false;
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sou(0,0,0,0);
	cout<<ans; 
	return 0;
}
