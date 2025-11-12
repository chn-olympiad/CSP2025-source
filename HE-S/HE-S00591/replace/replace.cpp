#include<bits/stdc++.h>
using namespace std;
int n,m,q;
string s[500005][3];
int cnt;
bool rp(string a,string b,string c,int w)
{
    string gc="";
    for(int i=0;i<w;i++)
    {
        gc+=a[i];
    }
    //cout<<gc<<endl;
    for(int i=0;i<c.size();i++)
    {
        gc+=c[i];
    }
    //cout<<gc<<endl;
    for(int i=w+c.size();i<a.size();i++)
    {
        gc+=a[i];
    }
   // cout<<gc<<endl;
    if(gc==b)
    {
        return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i][1]>>s[i][2];
    }
    for(int i=1;i<=q;i++)
    {
        string st,go;
        cin>>st>>go;
        cnt=0;
        st='0'+st;
        go='0'+go;
        for(int i=1;i<=n;i++)
        {
            int now=0;
            int ww;
            //cout<<st.find(s[i][1],2);
            //1 1 abc cde abccde cdecde
            while(ww=st.find(s[i][1],now))
            {
                if(ww==-1)
                {
                    break;
                }
                now=ww+1;
                if(rp(st,go,s[i][2],ww))
                {
                    cnt++;
                }
            }

        }
        cout<<cnt<<endl;
    }

    return 0;
}
