#include<bits/stdc++.h>
int a[500005],n,k,r=0,d=0;
int main(void)
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0; i<n; ++i)
		scanf("%d",a+i);
	for(int i=1; i<n; ++i)
		a[i]^=a[i-1];
	if(n<100000)
	{
		for(int i=0; i<n; ++i)
			for(int j=i; j>=d; --j)
				if((a[i]^a[j-1])==k)
					d=i+1,++r;
	}
	else
	{
		std::set<int>st;
		for(int i=0; i<n; ++i)
		{
			if(st.find(a[i]^k)!=st.end())
				++r,st.clear();
			st.insert(a[i]);
		}
	}
	printf("%d",r);
	return 0;
}//rp++
