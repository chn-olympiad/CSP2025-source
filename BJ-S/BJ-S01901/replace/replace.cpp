#include<bits/stdc++.h>
using namespace std;

string s[2*114514],t[2*114514];
int tot=0;
unordered_map<string,int> m;
// unordered_map<int,int> ch[5*1145140];
// vector<pair<int,int> >gua_a[5*1145140];
// vector<pair<int,int> >gua_b[5*1145140];

// int cnt[5*1145140];

// void insert(int node,int a,int b,int now,int len){
//     if(now==len){
//         cnt[node]++;
//         return;
//     }
//     // if(s[a][now]=='|'){gub_b[node].push_back(make_pair(b,now));return;}
//     // if(s[b][now]=='|'){gub_a[node].push_back(make_pair(a,now));return;}
//     int nxt=(s[a][now]-'a')*27+s[b][now]-'a';
//     if(ch[node].count(nxt)==0)ch[node][nxt]=++tot;
//     insert(ch[node][nxt],a,b,now+1,len);
// }

// int check(int node,string &a,string &b,int now,int len){
//     if(now==len)return cnt[node];
//     pushdown(node);
//     int nxt=(a[now]-'a')*27+b[now]-'a';
//     if(ch[node].count(nxt)==0)return cnt[node];
//     return cnt[node]+check(ch[node][nxt],a,b,now+1,len);
// }

int main(){//cout<<char('a'+27)<<endl;
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    

    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        string s,t;
        cin>>s>>t;
        if(s==t)continue;
        int len=s.size();
        int start=-1,end=-1;
        for(int i=0;i<len;i++)
            if(s[i]!=t[i]){
                if(start==-1)start=i;
                end=i;
            }
        string aa=s.substr(0,start),b=s.substr(start,end-start+1),c=s.substr(end+1,len-end-1),bb=t.substr(start,end-start+1),a=aa;
        for(int i=0;i<start;i++)a[i]=aa[start-i-1];
        // if(m.count(b+bb)==0)m[b+bb]=++tot;
        // int sza=a.size(),szc=c.size();
        // if(sza<szc)for(int i=0;i<szc-sza;i++)a+='|';
        // if(sza>szc)for(int i=0;i<sza-szc;i++)c+='|';
        m[b+' '+bb+' '+a+' '+c]++;
        // insert(m[b+bb],a,c,0,a.size());
        // cout<<a<<' '<<c<<' '<<b<<' '<<bb<<endl;
    }

    while(q--){
        string s,t;
        cin>>s>>t;
        int len=s.size();
        int start=-1,end=-1;
        for(int i=0;i<len;i++)
            if(s[i]!=t[i]){
                if(start==-1)start=i;
                end=i;
            }
        string aa=s.substr(0,start),b=s.substr(start,end-start+1),c=s.substr(end+1,len-end-1),bb=t.substr(start,end-start+1),a=aa;
        for(int i=0;i<start;i++)a[i]=aa[start-i-1];
        // int sza=a.size(),szc=c.size();
        // if(sza<szc)for(int i=0;i<szc-sza;i++)a+='|';
        // if(sza>szc)for(int i=0;i<sza-szc;i++)c+='|';
        // if(m.count(b+bb)==0){cout<<"0\n";continue;}
        // cout<<a<<' '<<c<<' '<<b<<' '<<bb<<endl;
        int ans=0;
        int sza=a.size(),szc=c.size();
        string now=b+' '+bb+' ',noww;
        for(int i=0;i<=sza;i++){
            if(i)now+=a[i-1];
            noww=now+' ';
            for(int j=0;j<=szc;j++){
                if(j)noww+=c[j-1];
                ans+=m[noww];
                // cout<<i<<' '<<j<<' '<<noww<<' '<<ans<<endl;
            }

        }
        cout<<ans<<'\n';
    }
}