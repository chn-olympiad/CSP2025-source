#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
bool book[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i<=n;i++)
        cin >> a[i];
    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
        for(int j =1;j<=n-i+1;j++)
        {
            b[j]=b[j]^a[j+i-1];
            if(b[j]==k)
            {
                int flag=0;
                for(int k = j;k<=j+i-1;k++)
                {
                    if(book[k])
                    {
                        flag=1;
                    }
                }
                if(!flag)
                {
                    ans++;
                    for(int k = j;k<=j+i-1;k++)
                    {
                        book[k]=1;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
