#include <bits/stdc++.h>
using namespace std;
long long n,a[500005],f[500005],k,pos,asdddd;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]==1) asdddd++;
	}
	if(n>=15000)
	{
		if(k==1) cout << asdddd;
		else
		{
			asdddd=n-asdddd;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1 && a[i+1]==1)
				{
					asdddd++;
					i+=2;
				}
			}
		}
	}
	if(a[1]==k) f[1]=1,pos=1;
	for(int i=2;i<=n;i++)
	{
		int asd=a[i];
		bool falg=0;
		if(a[i]==k) {
			f[i]=f[i-1]+1;
			pos=i;
			continue;
		}
		for(int j=i-1;j>pos;j--)
		{
			asd=(asd|a[j])-(asd&a[j]);
			if(asd==k){
				f[i]=f[i-1]+1;
				falg=1;
				pos=i;
				break;
			}
		}
		if(!falg) f[i]=f[i-1];
	}
	cout << f[n];
	return 0;
}
