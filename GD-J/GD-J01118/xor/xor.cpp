#include<bits/stdc++.h>
using namespace std;
struct akcsp_j{int a,b;}a[500005];
long long n,k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1,x;i<=n;++i)
	{
		cin>>x;
		a[i].b=0;
		if(x==k)
		{
			ans++;
			a[i].b=1;
		}
		a[i].a=a[i-1].a^x;
	}
	for(int i=2;i<=n;++i)
	{
		for(int j=1;j<=n-i+1;++j)
		{
			int akak=a[j+i-1].a^a[j-1].a;
			if(akak==k)
			{
				bool p=true;
				for(int l=j;l<=j+i-1;++l)
				{
					if(a[l].b==1)
					{
						p=false;
						break;
					}
				}
				if(p)
				{
					ans++;
					for(int l=j;l<=j+i-1;++l)
						a[l].b=1;
				}
			}
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
