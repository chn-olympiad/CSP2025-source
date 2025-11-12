#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
string s,t;
struct node
{
    string a,b,xx;
    ll id;//第一个不同的位置
}a[200200];
bool cmp(node a,node b)
{
    return a.a<b.a;
}
ll tmp=0;
map<string,ll> mp;
vector<node> v[200200];
string turn(ll x)
{
    string s=" ";
    if(x==0) return " 0";
    ll t=1e10;
    while(x/t==0) t/=10;
    while(t!=0)
    {
    //    cout<<x/t<<endl;
        s+=((x/t)+'0');
        x-=x/t*t;t/=10;
    }
//    cout<<"yes"<<endl;
    return s;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].a>>a[i].b;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<a[i].a.size();j++)
        {
            if(a[i].a[j]!=a[i].b[j])
            {
            //    cout<<"yes"<<a[i].xx<<","<<endl;
                if(a[i].xx.size()==0)
                {
            //        cout<<"yes"<<endl;
                    a[i].id=j;
                }
            //    cout<<j<<endl;
            //    cout<<turn(j)<<endl;
                a[i].xx+=turn(j-a[i].id);
            }
        }
    //    cout<<a[i].xx<<endl;
        if(mp[a[i].xx]==0)
        {
            tmp++;
            mp[a[i].xx]=tmp;
        }
        ll sss=mp[a[i].xx];
        v[sss].push_back(a[i]);
    }
    /*
    for(int i=1;i<=tmp;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j].a<<" "<<v[i][j].b<<endl;
        }
        cout<<endl;
    }//*/
    while(q--)
    {
        cin>>s>>t;string tt="";ll st=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=t[i])
            {
                if(tt.size()==0) st=i;
                tt+=turn(i-st);
            }
        }
        if(mp[tt]==0)
        {
            cout<<0<<endl;
            continue;
        }
        ll sss=mp[tt],ans=0;
        for(int j=0;j<v[sss].size();j++)
        {
            node x=v[sss][j];
            ll tui=st-x.id;
            if(tui<0) continue;
            if(x.a.size()-x.id+st>s.size()) continue;
            bool flag=true;
            for(int i=0;i<x.a.size();i++)
            {
                if(s[i+tui]!=x.a[i]||t[i+tui]!=x.b[i])
                {
                    flag=false;
                    break;
                }
            }
            if(flag==true) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
