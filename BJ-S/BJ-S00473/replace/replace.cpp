#include <bits/stdc++.h>
using namespace std;
int n,q,place,ans[200010];
string s[200010][2],t[200010][2];

string rp(int p,string been,string be)
{
    for(int i=p;i<=p+be.size()-1;i++)
    {
        been[i]=be[i];
    }
    return been;
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i][0]>>s[i][1];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>t[i][0]>>t[i][1];
    }
    for(int i=1;i<=q;i++)
    {
        for(int j=1;j<=n;j++)
        {
            place=t[i][0].find(s[j][0]);
            if(place!=-1 && rp(place,t[i][0],s[j][1])==t[i][1])
            {
                ans[i]++;
                //cout << s[j][0]<<endl;
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        cout << ans[i] <<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
