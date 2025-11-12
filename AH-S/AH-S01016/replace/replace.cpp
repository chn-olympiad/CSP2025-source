#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
string s[20111][3],q1,q2;
map<string,int> m;
int main()
{
	freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>s[i][1]>>s[i][2],m[s[i][1]]=i;
    while(q--)
    {
        cin>>q1>>q2;
        if(q1.length()!=q2.length())
        {
            puts("0");
            continue;
        }
        int st=0,ed=n-1,ans=0;
        while(q1[st]==q2[st]) ++st;
        while(q1[ed]==q2[ed]) --ed;
        string ss,t;
        for(int i=0;i<st;i++)
        {
            for(int j=n-1;j>ed;j--)
            {
                ss=q1[i+1],t=q2[i+1];
                for(int k=i+2;k<=j;k++)
                    ss=ss+q1[k],t=t+q2[k];
                if(m[ss])
                {
                    if(s[m[ss]][2]==t)
                        ++ans;
                }
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}
