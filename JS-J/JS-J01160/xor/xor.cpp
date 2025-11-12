#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,k,a[maxn],o[maxn],num=1;
long long ans;
struct node
{
	int l,r;
}b[maxn];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
			o[i]=o[i-1]+1;
		else
			o[i]=o[i-1];
	}
	for(int l=1;l<=n;l++)
	{
		int r=l;
		while(1)
		{
			if(r>n)
				break;
			if((o[r]-o[l-1])%2==k)
			{
				b[num].l=l;
				b[num].r=r;
				num++;
			}
			r++;
		}
	}
	for(int i=1;i<num;i++)
		for(int j=i+1;j<num;j++)
			if(b[j].l>b[i].r)
				ans++;
	cout<<num;
	return 0;
}