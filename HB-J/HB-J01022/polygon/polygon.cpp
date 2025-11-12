#include <bits/stdc++.h>
using namespace std;
int n,answer;
int a[5005];
bool work(int x)
{
	int cnt=0,sum=0,maxn=0;
	while(x!=0)
	{
		cnt++;
		if(x%2==1)
		{
			maxn=max(maxn,a[cnt]);
			sum+=a[cnt];
		}
		x/=2;
	}
	if(sum>2*maxn) return true;
	return false;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=7;i<=(int)pow(2,n);i++)
		if(work(i)) answer++;
	cout<<answer;
	return 0;
}
