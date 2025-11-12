#include<bits/stdc++.h>
using namespace std;
int n,k,temp1 = 1,temp2 = 1,tempAns = 0,ans = 0;
int a[1005] = {0};
int sum[1005][1005] = {{0}};
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++)
    {
        sum[i][i] = a[i];
        for(int j = i + 1;j <= n;j++) sum[i][j] = sum[i][j - 1] ^ a[j];
    }
    for(int i = 1;i <= n;i++)
    {
    	temp1 = temp2 = i;
    	tempAns = 0;
	    while(temp1 <= n)
	    {
	        if(sum[temp1][temp2] == k)
	        {
	            tempAns++;
	            temp1 = temp2 + 1;
	            temp2++;
	        }
	        else if(temp2 == n)
	        {
	            temp1++;
	            temp2 = temp1;
	        }
	        else temp2++;
	    }
	    ans = max(ans,tempAns);
	}
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
