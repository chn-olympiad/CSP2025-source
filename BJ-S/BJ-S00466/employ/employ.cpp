#include<bits/stdc++.h>
using namespace std;
const int N=510,M=998244353;
int s[N],c[N],a[N];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    char ch;
    for(int i=1;i<=n;i++)
    {
        cin>>ch;
        if(ch=='1') s[i]=1;
        else s[i]=0;
        a[i]=i;
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    int cnt,cnt1,ans=0;
    do
    {
        //for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        //cout<<endl;
        cnt=cnt1=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt>=c[a[i]]) cnt++;
            else if(s[i]==0) cnt++;
            else cnt1++;
        }
        if(cnt1>=m)ans=(ans+1)%M;
    }while(next_permutation(a+1,a+1+n));
    cout<<ans;
}
