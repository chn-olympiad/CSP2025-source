#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    freopen;{"seat.in","r";stdin;}
    freopen;{"seat.out","r";stdin;}
    int n,m;
    cin>>n>>m;
    int s[n*m];
    int f[n][m];
    for(int i=0;i<n*m;i++)
    {
        cin>>s[i];
    }
    int a=s[0];
    sort(s,s+m*n);
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<m;j++)
        {
            f[i][j]=s[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int i=0;i<m;i++)
        {
            cout<<f[i]<<endl;
        }
        cout<<" ";
        for(int i=2;i<m+2;i++)
        {
            cout<<f[i]<<endl;
        }
        cout<<" ";
    }
    cout<<" "<<a;
    if(a==1) cout<<"sdasdas";
    return 0;
}
