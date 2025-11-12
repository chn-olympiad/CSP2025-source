#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;

int s[110];

bool cmp(int a,int b)
{
    return a > b;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,len;
    cin>>n>>m;
    len = n * m;
    for(int i = 1;i <= len;i ++)cin>>s[i];
    int k = s[1];
    sort(s + 1,s + 1 + len,cmp);
    int top = 1;
    for(int x = 1;x <= n;x ++)
    {
        int t = (x % 2 == 0) ? -1 : 1;
        int y = (t + 1 == 0) ? m : 1;
        for(;y <= m && y >= 1;y += t)
        {
            if(s[top] == k)
            {
                cout<<x<<" "<<y;
                return 0;
            }
            top ++;
        }
    }
    return 0;
}
