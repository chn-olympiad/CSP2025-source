#include <bits/stdc++.h>
using namespace std;

pair<string, string> p[200010];
string st[200010];
int n,q,top=1;

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> p[i].first >> p[i].second;
    while(q--)
    {
        string t1,t2,tmp;
        int cnt=0;
        cin >> t1 >> t2;
        tmp=t1;
        for(int i=0;i<t1.length();i++)
        {
            for(int j=i;j<t1.length();j++)
            {
                string s=t1.substr(i,j+1);
                if(s!=st[top-1]) st[top++]=s;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=top;j++)
            {
                if(st[j]==p[i].first)
                {
                    int id1=t1.find(st[j]);
                    string ans=t1.substr(0,id1);
                    ans+=p[i].second;
                    ans+=t1.substr(id1+st[j].length(),t1.length());
                    t1=ans;
                }
                if(t1==t2)
                {
                    cnt++;
                    t1=tmp;
                    break;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
