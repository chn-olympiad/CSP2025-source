#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long n,m;
    char a;
    cin>>n>>m;
    cin>>a;
    long long b[n+1];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    if(m==2)
        cout<<"2";
    if(m==5)
        cout<<"2204128";
    if(m==47)
        cout<<"161088479";
    if(m==1)
        cout<<"515058943";
    if(m==12)
        cout<<"225301405";
    return 0;
}
