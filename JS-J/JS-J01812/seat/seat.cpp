#include<bits/stdc++.h>
using namespace std;
int num[15*15];
int c,r;
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
    int sum=n*m;
    for(int i=1;i<=sum;i++)
        cin>>num[i];
    int k=num[1];
    sort(num+1,num+sum+1,cmp);
    int t=0;
    for(int i=1;i<=sum;i++)
        if(num[i]==k)
        {
            t=i;
            continue;
        }
    int a=t/n;
    int b=t%n;
    int c=a+1;
    int r=b;
    if(a%2!=0)
        r=n+1-b;
    cout<<c<<" "<<r<<endl;
    return 0;
}