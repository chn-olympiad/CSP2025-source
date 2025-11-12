#include<bits/stdc++.h>
using namespace std;
int a[100];
int p(int k)
{
    int sum=1;
    for(int i=1;i<=k;i++)
    {
        sum=sum*i;
    }
    return sum;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,s,num=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=3;i<=n;i++)
    {
        s=p(n)/p(n-i);
        if(s>0) num++;
    }
    cout<<num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
