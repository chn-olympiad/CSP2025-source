#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,i,k,ans;
    string s1[101],s2[101],t1,t2,tmp1,tmp2;
    cin>>n>>q;
    for(i=1;i<=n;i++)
        cin>>s1[i]>>s2[i];
    for(k=1;k<=q;k++)
    {
        cin>>t1>>t2;
        ans=0;
        for(i=1;i<=n;i++)
        {
            tmp1=t1;
            tmp2=t2;
            if(t1.find(s1[i])>=0 and t1.find(s1[i])<t1.size())
                tmp1.replace(t1.find(s1[i]),s1[i].size(),s2[i]);
            if(tmp1==tmp2)
                ans++;
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}