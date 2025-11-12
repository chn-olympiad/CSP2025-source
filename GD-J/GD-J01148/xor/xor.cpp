#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=1000000+10;
int n,k;
int list[MAXN];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	bool allOne=true;
	bool OneandZero=true;
	long long numOne=0;
	long long numZero=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&list[i]);
		if(list[i]!=1 && list[i]!=0)
		{
			OneandZero=false;
			allOne=false;
		}
		else if(list[i]!=1)allOne=false;
		if(list[i]==1)numOne++;
		if(list[i]==0)numZero++;
	}
	if(OneandZero&&k==0)
	{
		int oneAns=(numOne-(numOne%2))/2;
		cout<<oneAns+numZero;
		return 0;
	}
	if(OneandZero&&k==1)
	{
		cout<<numOne;
		return 0;
	}
	if(allOne && k==0)
	{
		cout<<(n-(n%2))/2;
		return 0;
	}
	return 0;
	
} 
