// 09:33 AC this problem

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,k,num[500005];
int sum[500005];
int tong[1<<21];

int main() 
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",num+i);
    for(int i=1;i<=n;i++)
        sum[i] = sum[i-1]^num[i];
    int lastr = 0, ans = 0;
    tong[0]++;
    for(int i=1;i<=n;i++) {
        int tmp = sum[i]^k;
        if(tong[tmp]) {
            for(int j=lastr;j<i;j++)
                tong[sum[j]]--;
            lastr = i;
            ans += 1;
        } tong[sum[i]]++;
    } printf("%d",ans);
    return 0;
}