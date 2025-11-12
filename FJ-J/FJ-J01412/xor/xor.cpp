#include <bits/stdc++.h>
using namespace std;
bool flag = true;
const int N = pow(2,20)+5;
int n,k,a[N],cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for (int i = 1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
    	if (a[i] == 1)
    	    cnt++;
		if (a[i]>1)
		    flag = false;
	}
	if (flag && k == 0)
	{
		printf("%d",cnt/2);
		return 0;
	}
	if (flag && k == 1)
	{
		printf("%d",cnt);
		return 0;
	}
	return 0;
}

