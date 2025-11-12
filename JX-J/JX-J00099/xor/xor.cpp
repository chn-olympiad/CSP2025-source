#include<iostream>
#include<cstdio>
using namespace std;

long long num[100005];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,l = 0;
    cin>>n>>k;
    for(int i = 0;i < n;i ++)cin>>num[i];
    for(int i = 0;i < n;i ++)
    {
        int t = num[i];
        if(t == k)
        {
            l ++;
            i ++;
            t = num[i];
        }
        else
        {
            i ++;
            while(t != k)
            {
                t ^= num[i];
                i ++;
            }
            l ++;
        }
    }
    cout<<l;
    return 0;
}
