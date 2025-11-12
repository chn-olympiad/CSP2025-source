#include<bits/stdc++.h>
using namespace std;
int cheak(string a,string b)
{
    bool y=true;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
            y=false;
    }
    return y;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,t=0;
    cin>>n>>q;
    string a[110],b[110],c[110],d[110];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int h=1;h<=q;h++)
    {
        cin>>c[h]>>d[h];
        t=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=q;j++)
            {
                if(cheak(c[j],a[i])&&cheak(d[j],b[i]))
                t++;
            }
        }
        cout<<t;
    }
    return 0;
}
