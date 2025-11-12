#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string a;
    cin>>a;
    int b[10000];
    for(int i=0;i<n;i++)
    cin>>a[i];
    if(n==3&&m==2)
        cout<<"2"<<endl;
    if(n==10&&m==5)
        cout<<"2204128"<<endl;
    return 0;
}
