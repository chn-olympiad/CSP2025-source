#include<bits/stdc++.h>
#define ln "\n"
using namespace std;
const int MAXN=100+10;
int a[MAXN]={0};
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+1+(n*m),cmp);
    int left=1,right=n*m;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(a[mid]==r)
        {
            left=mid;
            right=mid;
            break;
        }
        else if(a[mid]>=r)
        {
            left=mid+1;
        }
        else if(a[mid]<=r)
        {
            right=mid-1;
        }
    }
    int hang=0,lie=0;
    int x,y;
    x=left/(2*n);
    y=left%(2*n);
    if(y==0)
    {
        cout<<x*2<<" "<<1<<endl;
        return 0;
    }
    lie=x*2+1;
    if(y<=n)
    {
        hang=y;
    }
    else{
        hang=2*n-y+1;
        lie++;
    }
    cout<<lie<<" "<<hang<<ln;
    return 0;
}
