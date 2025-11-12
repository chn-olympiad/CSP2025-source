#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bitset<32> b;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l=0,maxl=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>k*2||(int)b.to_ulong()>k*2) break;
		if(a[i]==k)
		{
			if(b.to_ulong()!=0) b^=a[i];
			else l++;
			continue;
		}
		b^=a[i];
		if((int)b.to_ulong()==k)
		{
			l++;
			b=0;
			continue;
		}
	}
	if(b.to_ulong()==0&&l>maxl) maxl=l;
	if(maxl!=0) cout<<maxl<<endl;
	else cout<<1<<endl;
	return 0;
}
