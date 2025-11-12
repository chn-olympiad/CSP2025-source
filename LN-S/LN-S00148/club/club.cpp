#include<bits/stdc++.h>
using namespace std;
const int MAXN=2*1e5+10;
int a[3][MAXN];
struct srt{
    int maxi,mini,midi;
};
srt s[MAXN];
int n;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;cin>>T;
    while(T--)
    {
        cin>>n;
        bool keyA=1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[0][i]>>a[1][i]>>a[2][i];
            s[i].maxi= a[0][i]>a[1][i] ? 0:1;
            s[i].maxi= a[s[i].maxi][i]>a[2][i] ? s[i].maxi:2;

            s[i].mini= a[0][i]<a[1][i] ? 0:1;
            s[i].mini= a[s[i].mini][i]<a[2][i] ? s[i].mini:2;

            s[i].midi=3-s[i].mini-s[i].maxi;

            if(a[1][i]!=0||a[2][i]!=0)keyA=0;
        }
        if(n==2)
        {
            if(s[0].maxi!=s[1].maxi)ans+=a[s[0].maxi][0]+a[s[1].maxi][1];
            else ans=max(a[s[0].maxi][0]+a[s[1].midi][1],a[s[0].midi][0]+a[s[1].maxi][1]);
        }
        if(keyA)
        {
            sort(a[0],a[0]+n);
            for(int i=n/2;i<n;i++){
                    ans+=a[0][i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
