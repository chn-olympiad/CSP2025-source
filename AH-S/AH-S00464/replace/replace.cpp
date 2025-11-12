#include<bits/stdc++.h>
#define LL long long

using namespace std;
struct ch
{
string x,y,z;
};
unordered_map<string,queue<ch> > w;
queue<ch> qq;
int n,q;

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    string s1,s2,s,ss,sss;
    int cnt,cnt1,ans;
    ch a;
    for(int i=1;i<=n;i++)
    {
    cin>>s1>>s2;
    s="";
    ss="";
    cnt=0;
        if(s1==s2) continue;
        while(cnt<s1.length() && s1[cnt]==s2[cnt])
        {
        s=s+s1[cnt];
        cnt++;
        }
    a.x=s;
    s="";
    cnt1=s1.length()-1;
        while(cnt1>=0 && s1[cnt1]==s2[cnt1])
        {
        s=s1[cnt1]+s;
        cnt1--;
        }
    a.z=s;
    s="";
        for(int j=cnt;j<=cnt1;j++)
        {
        s=s+s1[j];
        ss=ss+s2[j];
        }
    a.y=s;
    w[ss].push(a);
    }
    for(int i=1;i<=q;i++)
    {
    cin>>s1>>s2;
    s="";
    ss="";
    cnt=0;
    ans=0;
        if(s1.length()!=s2.length())
        {
        printf("0\n");
        continue;
        }
        while(cnt<s1.length() && s1[cnt]==s2[cnt])
        {
        cnt++;
        }
    cnt1=s1.length()-1;
        while(cnt1>=0 && s1[cnt1]==s2[cnt1])
        {
        cnt1--;
        }
        for(int j=cnt;j<=cnt1;j++)
        {
        s=s+s1[j];
        ss=ss+s2[j];
        }
    cnt1++;
        while(!qq.empty())
        {
        qq.pop();
        }
        while(!w[s].empty())
        {
        a=w[s].front();
        qq.push(a);
        w[s].pop();
            if(a.y!=ss || cnt<a.x.length() || s1.length()-cnt1<a.z.length()) continue;
        sss="";
            for(int j=cnt-a.x.length();j<cnt;j++)
            {
            sss+=s2[j];
            }
            if(sss!=a.x) continue;
        sss="";
            for(int j=cnt1;j<cnt1+a.z.length();j++)
            {
            sss+=s2[j];
            }
            if(sss==a.z)
            {
            ans++;
            }
        }
    w[s]=qq;
    printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
