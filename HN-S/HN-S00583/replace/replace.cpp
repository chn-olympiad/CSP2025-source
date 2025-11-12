#include<bits/stdc++.h>
#define mm 200010
using namespace std;
int n,Q;
string t1[mm],t2[mm];
map<int,int> mp;
void work_B()
{
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        int add1=0,add2=0;
        for(int j=0;j<t1[i].size();j++)
        {
            if(t1[i][j]=='a') add1++;
            if(t1[i][j]=='b') add2++;
        }
        if(add1+add2!=t1[i].size() || add2!=1) flag=false;
    }
    for(int i=1;i<=n;i++)
    {
        int add1=0,add2=0;
        for(int j=0;j<t2[i].size();j++)
        {
            if(t2[i][j]=='a') add1++;
            if(t2[i][j]=='b') add2++;
        }
        if(add1+add2!=t2[i].size() || add2!=1) flag=false;
    }
    if(!flag) return ;
    for(int i=1;i<=n;i++)
    {
        int wz1,wz2;
        for(int j=0;j<t1[i].size();j++)if(t1[i][j]=='b') wz1=j;
        for(int j=0;j<t2[i].size();j++)if(t2[i][j]=='b') wz2=j;
        mp[wz1-wz2]++;
    }
    while(Q--)
    {
        string s1,s2;
        cin>>s1>>s2;
        int wz1,wz2;
        for(int j=0;j<s1.size();j++)if(s1[j]=='b') wz1=j;
        for(int j=0;j<s2.size();j++)if(s2[j]=='b') wz2=j;
        cout<<mp[wz1-wz2]<<'\n';
    }
    exit(0);
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>Q;
    for(int i=1;i<=n;i++) cin>>t1[i]>>t2[i];
    work_B();
    while(Q--)
    {
        if(n>10000){puts("0");continue;}
        string s1,s2;
        cin>>s1>>s2;
        int add=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<s1.size();j++)
            {
                bool flag=true;
                if(j+t1[i].size()>s1.size()) break;
                for(int k=0;k<t1[i].size();k++)if(t1[i][k]!=s1[j+k]){flag=false;break;}
                if(!flag) continue;
                for(int k=0;k<t2[i].size();k++) s1[j+k]=t2[i][k];
                bool flag2=true;
                for(int k=0;k<s1.size();k++)if(s1[k]!=s2[k]){flag2=false;break;}
                for(int k=0;k<t1[i].size();k++) s1[j+k]=t1[i][k];
                if(flag2) add++;
            }
        }
        printf("%d\n",add);
    }
}
/*
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
*/