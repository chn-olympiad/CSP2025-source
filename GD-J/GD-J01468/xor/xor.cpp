#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=(s[i-1]^a[i]);
	}
	int l=1,r=1;
	while(l<=n)
	{
		if((s[r]^s[l-1])==k)
		{
			ans++;
			l=r+1,r=l;
		}
		else
			if(r==n)
				l++,r=l;
			else
				r++;
	}
	cout<<ans;
	
	return 0;
}
