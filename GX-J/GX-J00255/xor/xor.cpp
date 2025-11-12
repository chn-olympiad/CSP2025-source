/*
lao tian bao you
neng na >= 30 fen
qiu ni le zhen de
wo xue bian cheng zhe me ren zhen
*/
#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+7;
int n,k;
int a[N];
bool checkA()
{
    for(int i=1;i<=n;i++)
        if(a[i]!=1)
            return 0;
    return 1;
}
bool checkB()
{
    for(int i=1;i<=n;i++)
        if(a[i]!=1 && a[i]!=0)
            return 0;
    return 1;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
   cin >> n >> k;
   for(int i=1;i<=n;i++)
   {
        cin >> a[i];
   }
    if(checkA())
    {
        if(k>1)
        {
            cout << 0;
        }
        else if(k==1)
        {
            cout << n;
        }
        else
        {
            cout << n/2;
        }

        return 0;
    }

    if(checkB())
    {
        if(k>1)
        {
            cout << 0;
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==k)
                cnt++;
        }
        cout << cnt;
        return 0;
    }
    cout << 0;
    return 0;
}
