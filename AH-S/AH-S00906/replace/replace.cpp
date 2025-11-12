#include<bits/stdc++.h>
using namespace std;
struct u
{
    string w1,w2,d1,d2;
    int l;
};
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    u s[n];
    string t1,t2,temp;
    for(int i=0;i<n;i++)
    {
        cin>>s[i].w1>>s[i].w2;
        for(int j=0;j<s[i].w1.length();j++)
        {
            if(s[i].w1[j]!=s[i].w2[j])
            {
                s[i].d1+=s[i].w1[j];
                s[i].d2+=s[i].w2[j];
            }
        }
        s[i].l=s[i].w1.length();
    }
    for(int i=0;i<q;i++)
    {
        int ans=0;
        cin>>t1>>t2;
        string dif="",ot="";
        for(int j=0;j<t1.length();j++)
        {
            if(t1[j]!=t2[j])
            {
                dif+=t1[j];
                ot+=t2[j];
            }
        }
        for(int j=0;j<n;j++)
        {
            if(dif==s[j].d1&&ot==s[j].d2)
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
