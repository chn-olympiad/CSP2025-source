#include<iostream>
#include<algorithm>
using namespace std;
bool bj(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n,m;
    int l=1,h=1;
    int r;
    int a[105];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    r=a[1];
    sort(a+1,a+n*m+1,bj);
    for(int i=1;i<=n*m;i++)
    {
        if(i%n==1&&i>n)
        {
            l++;
            if(l%2==0) h=m;
            else h=1;
        }
        //cout<<l<<" "<<h<<'\n';
        if(a[i]==r)
        {
            cout<<l<<" "<<h<<'\n';
            return 0;
        }
        if(l%2==0) h--;
        else h++;
    }
    return 0;
}
