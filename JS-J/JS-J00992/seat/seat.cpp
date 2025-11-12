#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct A
{
    ll c;
    ll num;
};
ll n,m;
A a[10000];
ll b[100][100];
bool cmp(A x,A y)
{
    return x.c>y.c;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i].c;
        a[i].num=i;
    }
    sort(a+1,a+n*m+1,cmp);
    ll k=1;
    ll i=1,j=1;
    bool flag=false;
    while(a[k].num!=1)
    {
        //cout<<b[i][j]<<" "<<i<<" "<<j<<" "<<a[k].c<<" "<<k<<endl;
        if(!flag)
        {
            if(i!=n)
            {
                b[i][j]=a[k].c;
                k++;
                i++;
            }
            else{
                b[i][j]=a[k].c;
                k++;
                flag=true;
                j++;
            }
        }
        else{
            if(i!=1)
            {
                b[i][j]=a[k].c;
                k++;
                i--;
            }
            else{
                b[i][j]=a[k].c;
                k++;
                j++;
                flag=true;
            }
        }
    }
    cout<<j<<" "<<i;
    return 0;
}

