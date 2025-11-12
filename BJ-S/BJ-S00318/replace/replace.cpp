#include <bits/stdc++.h>

using namespace std;
const int MAX=2e5+6,MAXS=1e9+9;
string a1[MAX],a2[MAX],q1,q2;//a=97
int x[MAX],s;
int n,q;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a1[i]>>a2[i];
        s=0;
        for(int j=0;j<a1[i].size();j++) s+=a1[i][j]-a2[i][j];
        x[s]++;
    }
    while(q--)
    {
        cin>>q1>>q2;
        s=0;
        for(int i=0;i<q1.size();i++) s+=q1[i]-q2[i];
        cout<<x[s]<<endl;
        
    }

    return 0;
}
