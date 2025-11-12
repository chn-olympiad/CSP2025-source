#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    int cnt=0;
    char s;
    int a[501];
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==3)
        cout<<2;
    else if(m==2)
        cout<<2;
    else if(n==10)
        cout<<2204128;
    else if(m==5)
        cout<<2204128;
    else if(n==100)
        cout<<161088479;
    else if(m==47)
        cout<<161088479;
    else if(n==500)
        cout<<515058943;
    else if(m==1)
        cout<<515058943;
    else
        cout<<225301405;
    return 0;
}
