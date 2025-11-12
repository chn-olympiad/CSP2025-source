#include<iostream>
#include<vector>
using namespace std;
int n,m,l[1000010],r[1000010];
string s1[1000010],s2[1000010],str1,str2;
vector<int>p[2000000];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
        l[i]=r[i]=-1;
        for(int j=0;j<s1[i].size();j++)
            if(s1[i][j]!=s2[i][j])
                r[i]=j,l[i]=(l[i]==-1?j:l[i]);
        int hs1=0,hs2=0;
        for(int j=l[i];j<=r[i];j++)
            hs1=(hs1*131+s1[i][j]-'a')%114513,hs2=(hs2*87+s2[i][j]-'a')%191981;
        p[(hs1*7717+hs2)%197237].push_back(i);
    }
    while(m--)
    {
        cin>>str1>>str2;
        int lk=-1,rk=-1;
        if(str1.size()!=str2.size())
        {
            cout<<0<<endl;
            continue;
        }
        for(int j=0;j<str1.size();j++)
            if(str1[j]!=str2[j])
                rk=j,lk=(lk==-1?j:lk);
        int hs1=0,hs2=0;
        for(int j=lk;j<=rk;j++)
            hs1=(hs1*131+str1[j]-'a')%114513,hs2=(hs2*87+str2[j]-'a')%191981;
        int ans=0;
        for(auto i:p[(hs1*7717+hs2)%197237])
            if(lk>=l[i]&&str1.size()-rk>=s1[i].size()-r[i])
            {
                bool b=0;
                for(int j=l[i]-1,k=lk-1;j>=0;j--,k--)
                    if(s1[i][j]!=str1[k])
                        b=1;
                for(int j=r[i]+1,k=rk+1;j<s1[i].size();j++,k++)
                    if(s1[i][j]!=str1[k])
                        b=1;
                if(!b)
                    ans++;
            }
        cout<<ans<<endl;
    }
    return 0;

}
