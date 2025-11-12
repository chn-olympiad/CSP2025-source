#include<bits/stdc++.h>
using namespace std;
string s[200005][3];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,i;
    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
        cin>>s[i][1]>>s[i][2];
    }
    while(q--)
    {
        string a,b;
        cin>>a>>b;
        int w,e;
        for(w=0;w<a.size();w++)
            if(a[w]!=b[w])
                break;
        for(e=a.size()-1;e>=0;e--)
            if(a[e]!=b[e])
                break;
        //cout<<w<<" "<<e<<endl;
        int l,r;
        int cnt=0;
        for(l=0;l<=w;l++)
        {
            for(r=e;r<a.size();r++)
            {
                string x,y;
                x=a.substr(l,r-l+1);
                y=b.substr(l,r-l+1);
                for(i=1;i<=n;i++)
                {
                    if(x==s[i][1]&&y==s[i][2])
                    {
                        cnt++;
                        break;
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
