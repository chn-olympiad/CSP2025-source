#include<bits/stdc++.h>
using namespace std;
int a[111];
bool cmp(int a,int b){return a>b;}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,f=-1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int tmp=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++) if(a[i]==tmp) f=i;
    for(int i=0,j=0,pos=-1,k=1;;i+=pos,k++)
    {
        if(i==0) i=1,j++,pos=-pos;
        if(i==n+1) i=n,j++,pos=-pos;
        if(k==f)
        {
            cout<<j<<" "<<i<<endl;
            break;
        }
    }
    return 0;
}
