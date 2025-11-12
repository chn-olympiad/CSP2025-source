#include<bits/stdc++.h>
using namespace std;
const int N=10+5;
const int M=10+5;
int a[N*M],n,m,k;
int X=1,Y=1;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int d=n*m;
    for(int i=1;i<=d;i++)
        cin>>a[i];
    k=a[1];
    sort(a+1,a+1+d,cmp);
    for(int i=1;i<=d;i++)
    {
        if(a[i]==k) break;
        if(Y%2!=0) X++;
        if(Y%2==0) X--;
        if(X>n) X--,Y++;
        if(X<1) X++,Y++;
    }
    cout<<Y<<" "<<X<<endl;
    return 0;
}

