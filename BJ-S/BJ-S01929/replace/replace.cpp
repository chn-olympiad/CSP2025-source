#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int S=5e6+5;
char c[2][S];
string s[N][2],t[N][2];
int anshv[N];
int n,q;
struct node
{
    int son[26];
    vector<int> id;
};
node tr[N<<2];
int tot;
map<string,map<string,int> > qmp;
map<string,map<string,int> > hmp;
string sub(string x,int st,int ed)
{
    string y="";
    for(int i=st;i<=ed;i++)y+=x[i];
    return y;
}
string flp(string x)
{
    string y="";
    int sz=x.size();
    for(int i=sz-1;i>=0;i--)y+=x[i];
    return y;
}
void insert(int qwq,int rt,string x)
{
    int sz=x.size();
    int nw=rt;
    for(int i=0;i<sz;i++)
    {
        if(!tr[nw].son[x[i]-'a'])tr[nw].son[x[i]-'a']=++tot;
        nw=tr[nw].son[x[i]-'a'];
    }
//    cout<<"add:"<<nw<<' '<<qwq<<endl;
    tr[nw].id.push_back(qwq);
}
void query(int rt,string x)
{
//    cout<<"qu:"<<x<<endl;
    int sz=x.size();
    int nw=rt;
    if(!tr[nw].id.empty())
    {
        for(int j=0;j<tr[nw].id.size();j++)anshv[tr[nw].id[j]]++;
    }
    for(int i=0;i<sz;i++)
    {
        if(!tr[nw].son[x[i]-'a'])break;
        nw=tr[nw].son[x[i]-'a'];
        if(!tr[nw].id.empty())
        {
            for(int j=0;j<tr[nw].id.size();j++)anshv[tr[nw].id[j]]++;
        }
    }
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        scanf("%s%s",c[0],c[1]);
        s[i][0]=c[0];
        s[i][1]=c[1];
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%s%s",c[0],c[1]);
        t[i][0]=c[0];
        t[i][1]=c[1];
    }
    string sa,sb;
    vector<int> ansa,ansb;
    int sz,ans=0;
    int l=1e9,r=0;
    for(int i=1;i<=n;i++)
    {
        sa="";
        sb="";
        sz=s[i][0].size();
        l=1e9;
        r=0;
        for(int j=0;j<sz;j++)
        {
            if(s[i][0][j]!=s[i][1][j])
            {
                l=min(l,j);
                r=max(r,j);
            }
        }
        if(l==1e9)continue;
        sa=sub(s[i][0],l,r);
        sb=sub(s[i][1],l,r);
        if(!qmp[sa][sb])
        {
            qmp[sa][sb]=++tot;
            hmp[sa][sb]=++tot;
        }
//            cout<<"----"<<endl;
        insert(i,qmp[sa][sb],flp(sub(s[i][0],0,l-1)));
        insert(i,hmp[sa][sb],sub(s[i][0],r+1,sz-1));
    }
    for(int i=1;i<=q;i++)
    {
        sa="";
        sb="";
        ans=0;
        sz=t[i][0].size();
        l=1e9;
        r=0;
        for(int j=0;j<sz;j++)
        {
            if(t[i][0][j]!=t[i][1][j])
            {
                l=min(l,j);
                r=max(r,j);
            }
        }
        sa=sub(t[i][0],l,r);
        sb=sub(t[i][1],l,r);
        for(int j=1;j<=n;j++)anshv[j]=0;
//            cout<<"nw:"<<l<<endl;
        query(qmp[sa][sb],flp(sub(t[i][0],0,l-1)));
        query(hmp[sa][sb],sub(t[i][0],r+1,sz-1));
//            for(int j=1;j<=n;j++)
//            {
//                cout<<"nw:"<<anshv[j]<<endl;
//            }
        for(int j=1;j<=n;j++)if(anshv[j]==2)ans++;
        printf("%d\n",ans);
    }
    return 0;
}
