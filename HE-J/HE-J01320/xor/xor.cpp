#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n , k;
long long a[N],sum[N],ans,b[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i],b[i] = -1;
    for(int i = 1;i <= n;i++) sum[i] = (sum[i-1] ^ a[i]);
    for(int i = 1;i <= n;i++)
    {
    	for(int j = i;j <= n;j++)
    	{
    		if((sum[i - 1] ^ sum[j]) == k)
    		{
    			b[i] = j;
    			break;
			}
		}
	}  
	int now = 0;
	for(int i = 1;i <= n;i++)
	{
	    if(b[i] == -1 || b[i] == now) continue;
		bool t = true;
		for(int j = i;j <= b[i];j++)
		if(b[j] < b[i] && b[j] != -1)
		{
		   t = false;
		   break;	
		}
		if(t == true) ans++ , now = b[i];	
	}                 
//    for(int i = 1;i <= n;i++)
//    {
//    	long long mx = -1;
//    	for(int j = i + 1;j <= b[i] - 1;j++)
//    	{
//    		if(b[j] < b[i] && b[j] != -1)
//    		{
//    			mx = b[j];
//    			ans++;
//			}
//		}
//		if(mx == -1) ans++ ,i = b[i] + 1;
//		else i = mx + 1;
//	}
	cout << ans;
	return 0;
}
