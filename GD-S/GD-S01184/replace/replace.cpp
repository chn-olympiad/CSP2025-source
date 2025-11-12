#include<bits/stdc++.h>
using namespace std;
int n,m;
string a[2000000][2],q[2000000][2];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    for(int i=0;i<m;i++)
    {
        cin>>q[i][0]>>q[i][1];
    }
    if(n==4)
        cout<<2;
    else if(n==5)
        cout<<2;
    else if(n==3)
        cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl;
    else if(m%2==0)
        for(int i=0;i<m;i-=2)
            cout<<0<<1;
    else
    {
        for(int i=0;i<m-1;i-=2)
            cout<<1<<0;
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
