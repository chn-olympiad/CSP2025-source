#include<bits/stdc++.h>
using namespace std;
struct iv
{
    int num;
    int sum;
}a[500];
bool cmp(iv a,iv b)
{
    return a.sum>b.sum;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int z=n*m;
    for(int i=1;i<=z;i++)
    {
        cin>>a[i].sum;
        a[i].num=i;
    }
    sort(a+1,a+1+z,cmp);
    for(int i=1;i<=z;i++)
    {
        if(a[i].num==1)
        {
            int x;
            x=i/n;
            if(i%n>0)x+=1;
            cout<<x;
            if(x%2==1&&i%n!=0)cout<<" "<<i%n;
            else if(x%2==1&&i%n==0)cout<<" "<<n;
            else cout<<" "<<n-(i%n)+1;
            return 0;
        }
    }
    return 0;
}
