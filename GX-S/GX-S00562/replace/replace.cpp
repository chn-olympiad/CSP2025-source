#include<iostream>
#include<string>
#include<vector>
using namespace std;
int n,q;
struct S
{
    string s1,s2;
};
vector<S>s;
string my_get(string str,int l,int r)
{
    string ans="";
    for(int i=l;i<=r;i++)ans=ans+str[i];
    return ans;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        s.push_back(S{s1,s2});
    }
    while(q--)
    {
        string t1,t2;
        cin>>t1>>t2;
        if(t1.length()!=t2.length())
        {
            cout<<0<<endl;
            continue;
        }
        int len=t1.length(),ans=0;
        t1=" "+t1+"     ",t2=" "+t2+"     ";
        for(int l=1;l<=len;l++)
            for(int r=l;r<=len;r++)
            {
                string x1=my_get(t1,1,l-1),y1=my_get(t1,l,r),z1=my_get(t1,r+1,n);
                string x2=my_get(t2,1,l-1),y2=my_get(t2,l,r),z2=my_get(t2,r+1,n);
                for(int i=0;i<n;i++)
                    if(y1==s[i].s1&&y2==s[i].s2&&x1==x2&&z1==z2)ans++;
            }
        cout<<ans<<endl;
    }
    return 0;
}
