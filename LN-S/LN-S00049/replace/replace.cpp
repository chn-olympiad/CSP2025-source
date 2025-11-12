#include <bits/stdc++.h>
using namespace std;
struct book
{
    string s,ss;
};
book a[5000010];
int n,q;
long long cnt;
string solve (string s,int id,int id2,int GG)
{
    string ss="";
    for (int i=0;i<=s.size()-1;i++)
    {
        if (i<id||i>id2)
        {
            ss=ss+s[i];
        }
        else
        {
            ss=ss+a[GG].ss[i-s.find (a[GG].s)];
        }
    }
    return ss;
}
int main ()
{
    freopen ("replace.in","r",stdin);
    freopen ("replace.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].s>>a[i].ss;
    }
    while (q--)
    {
        cnt=0;
        string s,ss,sss,ssss;
        cin>>s>>ss;
        sss=s;
        ssss=ss;
        for (int i=1;i<=n;i++)
        {
            s=sss;
            ss=ssss;
            long long he=0;
            while (s.find (a[i].s)!=-1)
            {
                if (solve (s,s.find (a[i].s),s.find (a[i].s)+a[i].s.size ()-1,i)==ss)
                {
                    he++;
                }
                s[s.find (a[i].s)]='$';
                ss[ss.find (a[i].s)]='$';
            }
            cnt=cnt+he;
        }
        cout<<cnt<<endl;
    }
    fclose (stdin);
    fclose (stdout);
    return 0;
}
