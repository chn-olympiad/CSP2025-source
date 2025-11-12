#include <bits/stdc++.h>
using namespace std;
int n,q;
struct node
{
    string x,y;
}t[200010];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>t[i].x>>t[i].y;
    while(q--)
    {
        string a,b;
        int num=0;
        cin>>a>>b;
        for(int i=1;i<=n;i++)
        {
            int p=b.find(t[i].y);
            if(p==-1) continue;
            string bb=b;
            string xx=t[i].x;
            for(int j=p;j<(p+xx.size());j++)
                bb[j]=xx[j-p];
            if(a==bb) num++;
            //cout<<bb<<endl;

        }
        cout<<num<<endl;
    }
    return 0;
}
