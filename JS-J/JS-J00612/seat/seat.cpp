#include<bits/stdc++.h>
using namespace std;
int l;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a;
    cin>>a;
    int num=m*n;
    int big=0;
    for(int i=1;i<num;i++)
    {
        cin>>l;
        if(l>a)
        {
            big++;
        }
    }
    big++;
    int n1,m1;
    if(big%n==0)
    {
        n1=big/n;
        if(n1%2==1)
        {
            m1=n;
        }
        else
        {
            m1=1;
        }
    }
    else
    {
        n1=big/n+1;
        if(n1%2==1)
        {
            m1=big-(n1-1)*n;
        }
        else
        {
            m1=n1*n-big+1;
        }
    }
    cout<<n1<<" "<<m1;
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
