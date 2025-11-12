#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500050];
int wyc[500050];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    int i;
    i=1;
    bool p13=0;
    while(i<=n)
        {
            cin>>a[i];
            if(a[i]>1)p13=1;
            ++i;
        }
    if(p13==0&&k==1)
        {
            int s=0;
            i=1;
            while(i<=n)
                {
                    if(a[i]==1)++s;
                    ++i;
                }
            cout<<s;
            return 0;
        }
    i=1;
    int j;
    int s;
    while(i<=n)
        {
            j=i-1;
            s=a[i];
            wyc[i]=wyc[i-1];
            while(j>=0&&wyc[j]==wyc[i-1])
                {
                    if(s==k)
                        {
                            wyc[i]=wyc[j]+1;
                            break;
                        }
                    s^=a[j];
                    --j;
                }
            ++i;
        }
    // i=1;
    // while(i<=n)
    //     {
    //         cout<<wyc[i]<<' ';
    //         ++i;
    //     }
    cout<<wyc[n];
    return 0;
}