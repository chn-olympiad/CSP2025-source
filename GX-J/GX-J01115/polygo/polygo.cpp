##include<iostream>
using namespace std;
int a[10000000];
int main()
{
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   int n,max=-1;
   cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=3;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    if(a[1]+a[2]+a[3]>max*2)
        cout<<1;
    else
        cout<<0;
    return 0;
}
