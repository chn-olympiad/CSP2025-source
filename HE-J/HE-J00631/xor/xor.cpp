#include <bits/stdc++.h>
using namespace std;
//qrcvty_queue<int>
long long n,k,a[700005],l=1,r=1,s,ans;
long long xxr(long long a,long long b)
{
	return (a|b)&(~(a&b));
}
int main()
{
//	/*
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	 */
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%ld",&a[i]);
	}
	s=a[1];
	while(r<=n)
	{
		if(s==k)
		{
//			printf("sk   L%d r%d  aL%d  ar%d\n",l,r,a[l],a[r]);
			ans++;
			while(a[l]==0) 
			{
//				ans++;
				l--;
			}
			if(r<n)
			{
				r++;
				l=r;
				s=a[r];
				continue;
			}else{
				break;
			}
		}else if(s>k)
		{
//			printf("Sk   L%d r%d  aL%d  ar%d\n",l,r,a[l],a[r]);
//			s-=a[l];
			s=xxr(s,a[l]);
			l++;
			if(l>r)
			{
				if(r>=n)
					break;
//				r++;
////				s+=a[r];
//				xxr(s,a[r]);
			}
		}
		r++;
//		s+=a[r];
		s=xxr(s,a[r]);
//		printf("L%d r%d  aL%d  ar%d    S%d\n",l,r,a[l],a[r],s);
	}
	cout<<ans;
	return 0;
} 
