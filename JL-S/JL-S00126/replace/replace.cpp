#include<bits/stdc++.h>
using namespace std;
int n,m,s;
string c,a[20005][5],b[20005][5];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i][1]>>b[i][2];
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(b[j][1]==a[i][1]&&b[j][2]==a[i][2])s++;
        }
        cout<<s<<endl;
    }
    return 0;
}
