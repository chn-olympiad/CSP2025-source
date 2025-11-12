#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
int l=1,h=0,len;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    len=n*m;
    for(int i=1;i<=len;i++) cin>>a[i];
    int mb=a[1];
    sort(a+1,a+len+1);
    int cnt=0,flag=1,f=1;
    for(int i=len;i>=1;i--)
    {
        cnt++;
        if(cnt==n+1)
        {
            f=0;
            cnt=1;
            l++;
        }
        if(f==0)
        {
            f=1;
            if(l%2==0) h=n+1,flag=0;
            if(l%2==1) h=0,flag=1;
        }
        if(flag) h++;
        if(!flag) h--;
        if(a[i]==mb) break;
    }
    cout<<l<<" "<<h;
    return 0;
}