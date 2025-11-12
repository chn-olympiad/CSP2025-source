#include <bits/stdc++.h>
using namespace std;
int n,q;
string a[1000000][2],b[10000000][2];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    for(int j=1;j<=q;j++)
    {
        cin>>b[j][0]>>b[j][1];
    }
    for(int i=1;i<=q;i++)
    {
        int sum=0;
        for(int j=0;j<=max(b[i][0].size()-1,b[i][1].size()-1);j++)
        {
            if(b[i][1][j]==b[i][0][j])
            {
                sum++;
            }
        }
        if(sum!=0)
            cout<<b[i][0].size()-sum<<endl;
        else
            cout<<0<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
