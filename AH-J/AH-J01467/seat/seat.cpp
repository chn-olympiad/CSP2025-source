#include<bits/stdc++.h>
using namespace std;
int n,m,p,a,cnt,arr[1024],ans;
bool cmp(int x,int y)
{
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a;
            if(i==1&&j==1)p=a;
            cnt++;
            arr[cnt]=a;
        }
    }
    sort(arr+1,arr+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
    {
        if(arr[i]==p)
        {
            ans=i;
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int b;
        if(i%2==1)b=0;
        if(i%2==0)b=m+1;
        for(int j=1;j<=m;j++)
        {
            if(i%2==1)b++;
            if(i%2==0)b--;
            ans--;
            if(ans==0)
            {
                cout<<i<<" "<<b;
                return 0;
            }
        }
    }
    return 0;
}
