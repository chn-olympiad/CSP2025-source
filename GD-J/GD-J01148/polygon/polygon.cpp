#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=50000+10;
long long n,list[MAXN],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&list[i]);
	}
	sort(list,list+n);
	for(int i=2;i<n;i++)
	{
		long long max=list[i]*2;
		long long s=(1<<(i+1))-1;
		for(int j=s;j>0;j--)
		{
			long long p=j,total=0,num=0;
			long long pos=0;
			while(p!=0)
			{
				if(p%2==1){
					total+=list[pos];
					num++;
				}
				pos++;-
				p>>=1;
			}
			if(total>max && num>=3){
			ans++;
			ans%=998244353;
			}
		}
	}
	printf("%d",ans);
	return 0;
} 
