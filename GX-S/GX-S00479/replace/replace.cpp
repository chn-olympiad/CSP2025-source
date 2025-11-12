#include<bits/stdc++.h>
using namespace std;
int n,q;
bool p=true;
long long sum;
struct str{
    string s1,s2;
    int cha;
}a[200005];
bool pd(string s)
{
    int t=0;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]!='a'&&s[i]!='b') return false;
        if(s[i]=='b') t++;
        if(t>1) return false;
    }
    return true;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    //string op="9999";
    //cout<<op.find(op)-1<<endl;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].s1>>a[i].s2;
        if(p==true)
        {
            if(pd(a[i].s1)==false) p=false;
            else if(pd(a[i].s2)==false) p=false;
        }
        a[i].cha=a[i].s2.find('b')-a[i].s1.find('b');
    }
    while(q--)
    {
        sum=0;
        string x,y;
        cin>>x>>y;
        if(x.size()!=y.size())
        {
            printf("0\n");
            continue;
        }
        if(p==true&&pd(x)==true&&pd(y)==true)
        {
            for(int i=1;i<=n;i++)
            {
                if(y.find('b')-x.find('b')==a[i].cha) sum++;
            }
        printf("%lld\n",sum);
        continue;
        }
        for(int i=1;i<=n;i++)
        {
                int j=x.find(a[i].s1);
                //cout<<t<<" "<<a[i].s1<<" "<<j<<endl;
                if(j>=x.size()) continue;
                string t2=x;
                //cout<<t2<<" "<<y<<" "<<" "<<t<<endl;
                if(t2.replace(j,a[i].s1.size(),a[i].s2)==y) sum++;
        }
        printf("%lld\n",sum);
    }
    return 0;
    /*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
}

