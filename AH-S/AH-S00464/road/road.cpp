#include<bits/stdc++.h>
#define LL long long

using namespace std;
struct ch
{
string x,y,z;
};
vector<string,ch> w;
int n,q;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&q);
    string s1,s2,s,ss;
    int cnt=0;
    change a;
    for(int i=1;i<=n;i++)
    {
    scanf("%s%s",&s1,&s2);
    s1+='-';
    s2+='+';
    s="";
    ss="";
        while(s1[cnt]==s2[cnt])
        {
        s=s+s1[cnt++];
        }
        if(s1[cnt]=='-') continue;
    a.x=s;
    s="";
        while(s1[cnt]!=s2[cnt] && s1[cnt]!='-')
        {
        s=s+s2[cnt];
        ss=ss+s1[cnt++];
        }
    a.y=s;
    s="";
        while(s1[cnt]==s2[cnt])
        {
        s=s+s1[cnt++];
        }
    a.z=s;
    w[ss].push_back(a);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
