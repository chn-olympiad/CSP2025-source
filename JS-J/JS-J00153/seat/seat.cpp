#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{

    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,f;
    cin>>n>>m;
    int c[105]={};
    for(int i=1;i<=m*n;i++)
    {
        cin>>c[i];
        if(i==1)
        {
            f=c[i];
        }
    }
    sort(c+1,c+m*n+1,cmp);
    for(int i=1;i<=m*n;i++)
    {
        if(c[i]==f)
        {
            f=i;
        }
    }
    int t1,t2;
    t1=ceil(f/(1.0*n));
    t2=((f-1)%n)+1;
    if(t1%2==0)
    {
        t2=n-t2+1;
    }
    cout<<t1<<" "<<t2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
