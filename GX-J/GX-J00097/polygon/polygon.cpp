#include<bits/stdc++.h>
using namespace std;
bool db(int a,int b)
{
    return a>b;

}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,b[5001];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];

    }
    sort(b+1,b+n+1,db);
    int g=b[1];
    int a=0;
    for(int i=1;i<=n;i++)
{
    a=a+b[i];


}
if(n<=3)
{
if(a>g*2)
{
    cout<<1;

}
else
{
cout<<0;
}


}
//cout<<a;
    return 0;
}
