#include<bits/stdc++.h>
using namespace std;
bool cmp(char s,char y)
{

    return s > y;
}long long n,k,ans = 0,a[500005];
void v(long long i,long long sum,long long num)
{
    if(sum == k)
    {
        num ++;
        sum = 0;
    }
    if(i > n)
    {
        ans = max(ans,num);
        return ;
    }
    v(i + 1,sum ^ a[i],num);
    v(i + 1,sum,num);
}
int main()
{
    freopen("xor3.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin >> n >> k;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }
    //v(1,0,0);
    long long num = 0;
    for(int i = 1;i <= n;i ++)
    {
            num ^= a[i];
        if(num == k)
        {

            ans ++;
            num = 0;
            //i ++;
            continue;
        }
    }
    cout << ans;
    return 0;
}
