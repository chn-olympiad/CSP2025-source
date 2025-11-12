#include<bits/stdc++.h>
using namespace std;
string s[200005][2];
string t1,t2;
const int N=1e7+11,mod=1e9+7;
long long p[200005][2];
long long tp[1000005][2];
long long fpow(long long x,int k)
{
    if(k==0)return 1;
    long long tmp=fpow(x,k>>1);
    if(k&1)return tmp*tmp%mod*x%mod;
    return tmp*tmp%mod;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i][0]>>s[i][1];
        for(int j=0;j<s[i][0].size();j++)
        {
            p[i][0]*=N;
            p[i][0]%=mod;
            p[i][0]+=s[i][0][j];
            p[i][0]%=mod;
        }
        for(int j=0;j<s[i][1].size();j++)
        {
            p[i][1]*=N;
            p[i][1]%=mod;
            p[i][1]+=s[i][1][j];
            p[i][1]%=mod;
        }
    }
    while(q--)
    {
        int ans=0;
        cin>>t1>>t2;
        int l=0,r=0,i=0;
        while(t1[i]==t2[i])
        {
            i++;
            l=i;
        }
        i=0;
        while(t1[t1.size()-i-1]==t2[t2.size()-i-1])i++,r=i;
        for(i=1;i<=t1.size();i++)
        {
            tp[i][0]=tp[i-1][0]*N%mod+t1[i-1];
            tp[i][0]%=mod;
        }
        for(i=1;i<=t2.size();i++)
        {
            tp[i][1]=tp[i-1][1]*N%mod+t2[i-1];
            tp[i][1]%=mod;
        }
        for(i=1;i<=n;i++)
        {
            if(s[i][0].size()<t1.size()-r-l)continue;
            //cout<<s[i][0]<<endl;
            //cout<<s[i][1]<<endl;
            for(int j=l;j+s[i][0].size()>=t1.size()-r-1;j--)
            {
                int tmp1=tp[j+s[i][0].size()+1][0]-tp[j+1][0]*fpow(N,s[i][0].size())%mod;
                tmp1%=mod;
                tmp1+=mod;
                tmp1%=mod;
                int tmp2=tp[j+s[i][1].size()+1][1]-tp[j+1][1]*fpow(N,s[i][1].size())%mod;
                tmp2%=mod;
                tmp2+=mod;
                tmp2%=mod;
                //cout<<tmp1<<endl<<tmp2<<endl<<p[i][0]<<endl<<p[i][1]<<endl;
                if(tmp1==p[i][0]&&tmp2==p[i][1]&&s[i][0][0]==t1[j+1])ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
