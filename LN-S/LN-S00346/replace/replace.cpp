#include<iostream>
#include<cstdio>
using namespace std;
struct replace
{
    string rs,ns;
}a[200005];
string repl(string s,string b,string c)
{
    string ret="";
    if(s.find(b)!=string::npos)
    {
        string fir=s.substr(0,s.find(b));
        string sec=s.substr(s.find(b)+b.size());
        ret=fir+c+sec;
    }
    return ret;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].rs;
        cin>>a[i].ns;
    }
    //cout<<"yES!"<<endl;
    for(int i=1;i<=q;i++)
    {
        string s,tos;
        int cnt=0;
        cin>>s;
        cin>>tos;
        for(int j=1;j<=n;j++)
        {
            //cout<<"No!"<<endl;
            //string cot=s;
            if(repl(s,a[j].rs,a[j].ns)==tos)
            {
                cnt++;
            }
            //s=cot;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
