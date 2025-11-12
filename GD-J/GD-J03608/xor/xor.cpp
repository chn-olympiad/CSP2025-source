#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005],ans;
int b[1100000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),s[i]=s[i-1]^a[i];
	int x=0;
	for(int i=1;i<=n;i++)
	{
		if(x==0&&s[i]==k) ans++,x=i;
		int y=s[i]^k;
		if(b[y]>0&&b[y]>=x) ans++,x=i;
		b[s[i]]=i;
	}
	cout<<ans;
	return 0;
}
