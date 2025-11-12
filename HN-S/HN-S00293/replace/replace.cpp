#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,q,cnt1,cnt2;
string s[N][2],t[N][2];
map<string,int>m1,m2;
map<pair<int,int>,int>cnt; 
void solve1(){
       for(int i=1;i<=n;i++){  
        if(m1.find(s[i][1])==m1.end()) m1[s[i][1]]=++cnt1;
        if(m2.find(s[i][2])==m2.end()) m2[s[i][2]]=++cnt2;
        ++cnt[make_pair(m1[s[i][1]],m2[s[i][2]])]; 
    } 
    for(int i=1;i<=q;i++){  
        int len=t[i][1].size();
        t[i][1]=" "+t[i][1],t[i][2]=" "+t[i][2];
        int l=0,r=len+1;
        while(l<len){
            if(t[i][1][l+1]==t[i][2][l+1]) ++l;
            else break;
        }
        while(r>1){
            if(t[i][1][r-1]==t[i][2][r-1]) --r;
            else break;
        }
        ll ans=0;
        for(int L=1;L<=l+1;L++){
            string tp1="",tp2="";
            for(int R=L;R<=len;R++){
                tp1+=t[i][1][R],tp2+=t[i][2][R];
                if(R+1>=r) ans+=cnt[make_pair(m1[tp1],m2[tp2])];
            }
        }
        cout<<ans<<'\n';
    }
    return ;
} 
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2]; 
    for(int i=1;i<=q;i++) cin>>t[i][1]>>t[i][2];  
    solve1();
    return 0;
}