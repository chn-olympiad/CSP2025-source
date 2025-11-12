#include<bits/stdc++.h>
using namespace std;
#define N 5000010
int n,q;
vector<int> lnxt[N],rnxt[N];
string s1,s2,ip1[N],ip2[N],tmp;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int k=1;k<=n;k++)
    {
        cin>>s1>>s2;
        int len=s1.size();
        s1+="a";
        s2+="a";
        for(int i=len;i>0;i--)
        {
            s1[i]=s1[i-1];
            s2[i]=s2[i-1];
        }
        //cout<<s1<<endl<<s2;
        ip1[k]=s1,ip2[k]=s2;
        for(int i=1,j=0;i<=len;i++)
        {
            while(j&&s1[j+1]!=s1[i]) j=lnxt[k][j];
            if(s1[j+1]==s1[i]) j++;
            lnxt[k].push_back(j);
            //out<<"tst::"<<lnxt[k][j]<<endl;
        }
        /*for(int i=1,j=0;i<=len;i++)
        {
            while(s2[j+1]!=s2[i]) j=rnxt[k][j];
            if(s2[j+1]==s2[i]) j++;
            rnxt[k].push_back(j);
        }*/
    }
    //cout<<"TTT";
    while(q--)
    {
        cin>>s1>>s2;
        if(s1.size()!=s2.size())
        {
            cout<<0<<endl;
            continue;
        }
        int len=s1.size(),sz=0,ans=0;
        s1+="a";
        s2+="a";
        for(int i=len;i>0;i--)
        {
            s1[i]=s1[i-1];
            s2[i]=s2[i-1];
        }
        for(int i=1;i<=len;i++) if(s1[i]!=s2[i]) sz++;
        //cout<<"sz::"<<sz<<endl;
        for(int k=1;k<=n;k++) if(ip1[k].size()-1>=sz)
        {
            for(int i=1,j=0;i<=len;i++)
            {
                while(j&&ip1[k][j+1]!=s1[i]) j=lnxt[k][j];
                if(ip1[k][j+1]==s1[i]) j++;
                //cout<<"j:"<<j<<endl;
                if(j==ip1[k].size()-1)
                {
                    tmp=s1;
                    int f=0;
                    //cout<<"tst::"<<i<<" "<<i-j+1<<endl;
                    for(int c=i-j+1,c1=1;c<=i;c++,c1++)
                    {
                        tmp[c]=ip2[k][c1];
                    }
                    //cout<<"tst::"<<tmp<<endl;
                    for(int i=1;i<=len;i++) if(tmp[i]!=s2[i]) f=1;
                    if(!f) ans++;
                    j=lnxt[k][j];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

1 1
bc de
xabcx xadex
*/
//Ren5Jie4Di4Ling5%
