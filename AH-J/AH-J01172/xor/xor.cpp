#include<bits/stdc++.h>
using namespace std;
int n,k,a[5010],cnt;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;++i) cin>>a[i];
    if(k==0)
    {
        for(int i=0;i<n;++i)
        {
            if(a[i]==0) ++cnt;
            else
            {
                if(i+1<n&&a[i+1]==1)
                {
                    ++cnt;
                    ++i;
                }
            }
        }
    }
    else
    {
        for(int i=0;i<n;++i)
        {
            if(a[i]==1) cnt++;
        }
    }
    cout<<cnt;
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
