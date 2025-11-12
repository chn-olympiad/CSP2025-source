#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100050];
int len;
bool side=true;
int mainly;
int top=1;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    len=n*m;
    for(int i=1;i<=len;i++)
    {
        cin>>a[i];
    }
    mainly=a[1];
    sort(a+1,a+1+len,cmp);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[top]==mainly)
            {
                if(i%2==1)
                {
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
                else
                {
                    cout<<i<<" "<<(n-j+1)<<endl;
                }
            }
            top++;
        }
    }
    return 0;
}
