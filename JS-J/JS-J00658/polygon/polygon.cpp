#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int ma=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>=ma)
        {
            ma=a[i];
        }
    }
    if(ma==1)
    {
        cout<<n-2;
        return 0;
    }
    else if(n==3)
    {
        if(a[1]+a[2]+a[3]>2*ma)
        {
            cout<<1;
            return 0;
        }
        else
        {
            cout<<0;
            return 0;
        }
    }
    sort(a+1,a+n+1,cmp);
    int cnt=0;
    for(int i=1;i<=(1<<n)-1;i++)
    {
        //cout<< i <<"!"<<endl;
        int t=i;//recognize this bit
        int j=1;//record the num
        int o=0;//record the sum
        int maxn=-1;
        while(t)
        {
            //cout<<(t&1)<<" "<<o<<" "<<a[j]<<endl;
            if((t&1) && o==0)
            {
                maxn=a[j];
                o++;
            }
            else if(t&1)
            {
                maxn-=a[j];
                o++;
            }
            j++;
            t=t/2;
        }
        if(o>=3 && maxn<0)
        {
            cnt++;
            //cout<<cnt<<endl<<endl;
        }
    }
    cout<<cnt;
    return 0;
}
