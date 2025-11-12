#include <bits/stdc++.h>
using namespace std;
string s1[200001],s2,t1,t2,s3[200001],t3,s4[200001],t4;
int n,q,tmp1,tmp2,add,tmp4,ls[200001];
pair<int,int> s[200001];
long long ans;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;++i)
    {
        cin>>s1[i]>>s2;
        ls[i]=s2.length();
        for(int j=0;j<ls[i];++j)
        {
            if(s1[i][j]!=s2[j]){tmp1 = j;break;}
        }
        for(int j=ls[i]-1;j>=0;--j)
        {
            if(s1[i][j]!=s2[j]){tmp2 = j;break;}
        }
        for(int j=tmp1;j<=tmp2;++j)
        {
            s3[i]+=s1[i][j];
            s4[i]+=s2[j];
        }
        s[i].first = tmp1;s[i].second = tmp2;
    }
    for(int i=0;i<q;++i)
    {
        ans=0;
        cin>>t1>>t2;if(t1.length()!=t2.length()){cout<<0<<endl;continue;}
        for(int j=0;j<t1.length();++j)
        {
            if(t1[j]!=t2[j]){tmp1 = j;break;}
        }
        for(int j=t1.length()-1;j>=0;--j)
        {
            if(t1[j]!=t2[j]){tmp2 = j;break;}
        }
        t3="",t4="";
        for(int j=tmp1;j<=tmp2;++j)
        {
            t3+=t1[j];
            t4+=t2[j];
        }
        for(int j=0;j<n;++j)
        {
            if(s3[j]==t3&&s4[j]==t4)
            {
                add=1;
                for(int k=0;k<s[j].first;++k) if((k+tmp1-s[j].first)<0||s1[j][k]!=t1[k+tmp1-s[j].first]){add=0;break;}
                for(int k=s[j].second;k<ls[j];++k) if((k+tmp2-s[j].second)<0||s1[j][k]!=t1[k+tmp2-s[j].second]){add=0;break;}
                ans+=add;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
