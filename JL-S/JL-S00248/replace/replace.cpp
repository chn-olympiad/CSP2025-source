#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
string s[200002][2];
bool match1[200002]={false},match2[200002]={false};
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    string t1,t2,f1,f2;
    int n,q,i,l,r,ans=0;
    cin>>n>>q;
    for(i=1;i<=n;i++)
        cin>>s[i][0]>>s[i][1];
    while(q--)
    {
        cin>>t1>>t2;
        ans=0;
        memset(match1,false,sizeof(match1));
        memset(match2,false,sizeof(match2));
        if(t1.length()!=t2.length())
        {
            cout<<0<<endl;
            continue;
        }
        for(l=0;l<t1.length();l++)
            if(t1[l]!=t2[l])
                break;
        for(r=t1.length()-1;r>=0;r--)
            if(t1[r]!=t2[r])
                break;
        f1=t1.substr(l,r-l+1);
        f2=t2.substr(l,r-l+1);
        for(i=1;i<=n;i++)
        {
            if(s[i][0].find(f1)!=s[i][0].npos)
                match1[i]=true;
            if(s[i][1].find(f2)!=s[i][1].npos)
                match2[i]=true;
        }
        for(i=1;i<=n;i++)
            if(match1[i]&&match2[i]&&t1.find(s[i][0])!=t1.npos)
                ans++;
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
