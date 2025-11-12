#include <bits/stdc++.h>
using namespace std;
const int N=505;
int a[N],b[N];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=i;
    }
    int ans=0;
    do
    {
        int cnt1=0,cnt2=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt2>=a[b[i]])
            {
                cnt2++;
            }
            else
            {
                if(s[i-1]=='0')
                {
                    cnt2++;
                }
                else
                {
                    cnt1++;
                }
            }
        }
        if(cnt1>=m)
        {
            ans++;
        }
    }while(next_permutation(b+1,b+n+1));
    cout<<ans;
    return 0;
}
