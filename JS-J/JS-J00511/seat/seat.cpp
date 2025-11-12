#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,temp;
bool cmp(int x,int y)
{
    if(x>y)
        return 1;
    return 0;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int sp=n*m;
    for(int i=0;i<sp;i++)
    {
        cin>>a[i];
        if(i==0)
            temp=a[i];
    }
    sort(a,a+sp,cmp);
    for(int i=0;i<sp;i++)
        if(temp==a[i])
        {
            if((int(ceil(double(i+1)/double(n)))%2)==1)
                cout<<ceil(double(i+1)/double(n))<<' '<<i+1-((ceil(double(i+1)/double(n))-1)*n)<<endl;
            else
                cout<<ceil(double(i+1)/double(n))<<' '<<n-(i-((ceil(double(i+1)/double(n))-1)*n))<<endl;
            return 0;
        }
    return 0;
}
