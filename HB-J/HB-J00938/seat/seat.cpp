#include<bits/stdc++.h>
using namespace std;
//₣
//Ũ
//₵
//₭
//
//€
//₡
//₣
// Hei Hei Fa Xian Bu Liao Ba hhhhhhhhhhhhhh
int a[666];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    #ifndef debug
        freopen("seat.in","r",stdin);
        freopen("seat.out","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int r=a[1];
    sort(a+1,a+1+n*m,cmp);
    int pos=1;
    for(int i=1;i<=n*m;i++)
        if(a[i]==r)
        {
            pos=i;
            break;
        }
    int x=ceil(double(pos)/double(n)/1.0),y=1;
    pos%=n;
    if(x%2==0)
    {
        if(pos==0)y=1;
        else y=n-pos+1;
    }
    else
    {
        if(pos==0)y=n;
        else y=pos;
    }
    cout<<x<<" "<<y;
    return 0;
}
// Wo Yao Shang Mi Huo Xing Wei Da Shang
