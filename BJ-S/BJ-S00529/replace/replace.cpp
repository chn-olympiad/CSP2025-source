#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#define fin freopen("replace.in","r",stdin);
#define fout freopen("replace.out","w",stdout);
using namespace std;
int a1z26[1005];
int n,qs;
int real_change[200005];
pair<string,string> real_changes[200005];
int changecnt;
map<pair<string,string>,int> change_id;
string a[200005],b[200005];
class trie
{
public:
    int siz;
    int root[5000005],roots;
    char val[5000005];
    int son[5000005][28];
    vector<int> send[5000005];
    trie()
    {
        siz=roots=0;
        for(int i=0;i<=5000002;i++)
        {
            root[i]=0;
            val[i]='/';
            send[i].clear();
        }
    }
    void insert(const string& s,int x,int num)
    {
        if(x>roots)
        {
            roots++;
            root[roots]=++siz;
            val[siz]='R';
            for(int i=1;i<=26;i++)
                son[siz][i]=0;
        }
        int now=root[x];
        for(char c:s)
        {
            int id=a1z26[c];
            if(!son[now][id])
            {
                son[now][id]=++siz;
                val[siz]=c;
                for(int i=1;i<=26;i++)
                    son[siz][i]=0;
            }
            now=son[now][id];
        }
        send[now].push_back(num);
    }
    void query(const string& s,int x,bool* arr)
    {
        if(x>roots)
            return;
        int now=root[x];
        for(int i:send[now])
            arr[i]=1;
        for(char c:s)
        {
            int id=a1z26[c];
            if(!son[now][id])
                return;
            now=son[now][id];
            for(int i:send[now])
                arr[i]=1;
        }
    }
}fr,ba;

bool iffr[200005],ifba[200005];

void init()
{
    for(int i=1;i<=26;i++)
        a1z26['a'+i-1]=i;
}
int main()
{
    fin
    fout
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >> n >> qs;
    for(int i=1;i<=n;i++)
    {
        string s,t;
        cin >> s >> t;
        if(s==t)
            continue;
        int l=0,r=s.length()-1;
        while(s[l]==t[l])
            l++;
        while(s[r]==t[r])
            r--;
        pair<string,string> change=make_pair(s.substr(l,r-l+1),t.substr(l,r-l+1));
        if(change_id[change])
            real_change[i]=change_id[change];
        else
        {
            real_changes[++changecnt]=change;
            change_id[change]=changecnt;
            real_change[i]=changecnt;
        }
        a[i]=s.substr(0,l);
        b[i]=s.substr(r+1);
        //cout << a[i] << " (" << change.first << "->" << change.second << ") " << b[i] << endl;
        reverse(a[i].begin(),a[i].end());
        fr.insert(a[i],real_change[i],i);
        reverse(a[i].begin(),a[i].end());
        ba.insert(b[i],real_change[i],i);
    }
    for(int i=1;i<=qs;i++)
    {
        string s,t;
        cin >> s >> t;
        int l=0,r=s.length()-1;
        while(s[l]==t[l])
            l++;
        while(s[r]==t[r])
            r--;
        pair<string,string> change=make_pair(s.substr(l,r-l+1),t.substr(l,r-l+1));
        string aa=s.substr(0,l);
        string bb=s.substr(r+1);
        reverse(aa.begin(),aa.end());
        if(change_id.find(change)==change_id.end())
        {
            cout << "0\n";
            continue;
        }
        for(int i=1;i<=n;i++)
            iffr[i]=ifba[i]=0;
        fr.query(aa,change_id[change],iffr);
        ba.query(bb,change_id[change],ifba);
        int anss=0;
        for(int i=1;i<=n;i++)
            if(iffr[i] && ifba[i])
                anss++;
        cout << anss << endl;
    }
    return 0;
}
