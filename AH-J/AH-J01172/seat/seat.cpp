#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int s=n*m;
    for(int i=0;i<s;++i) cin>>a[i];
    int k=a[0];
    sort(a,a+s,cmp);
    int l=0,r=s-1,mid,cnt=0;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(a[mid]==k)
        {
            cnt=mid+1;
            break;
        }
        else if(a[mid]<k)r=mid-1;
        else l=mid+1;
    }
    int x=1,i=1,j=1;
    while(x<cnt)
    {
        if(j%2!=0)
        {
            if(i+1<=n) ++i;
            else ++j;
        }
        else
        {
            if(i-1>=1) --i;
            else ++j;
        }
        ++x;
    }
    cout<<j<<' '<<i;
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
