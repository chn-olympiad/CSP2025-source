#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int base1=13331;
const int base2=721;
const int N=2e5+10;
int n,q;
string tt,t;
string s[N][2];
map<int,int> mp;
int ot[N];
struct node{
    int len,gp,pla,num;
}rec[N],cp[N];
bool cmpp(node aa,node bb){
    return aa.pla<bb.pla;
}
int cmp(string a1,string a2,string a4){
    int ans=0;
    for(int i=1;i<=(a1.size()-a2.size()+1);i++){
        bool flag=true;
        for(int j=1;j<a2.size();j++){
            if(a2[j]!=a1[i+j-1]) flag=false;
        }
        if(flag){
            string a3=" ";
            for(int j=1;j<i;j++) a3+=a1[j];
            for(int j=1;j<a4.size();j++) a3+=a4[j];
            for(int j=i+a2.size()-1;j<a1.size();j++) a3+=a1[j];
            if(a3==t) ans++;
        }
    }
    return ans;
}

void solve(){
    for(int i=1;i<=n;i++){
        cp[i].len=(s[i][1].size()-s[i][0].size());
        for(int j=1;j<s[i][0].size();j++){
            if(s[i][0][j]=='b'){
                cp[i].pla=j;
                break;
            }
        }
        for(int j=1;j<s[i][0].size();j++){
            if(s[i][1][j]=='b'){
                cp[i].gp=j-cp[i].pla;
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>t>>tt;
        t=" "+t,tt=" "+tt;
        rec[i].len=(tt.size()-t.size());
        for(int j=1;j<t.size();j++){
            if(t[j]=='b'){
                rec[i].pla=j;
                break;
            }
        }
        for(int j=1;j<tt.size();j++){
            if(tt[j]=='b'){
                rec[i].gp=j-rec[i].pla;
            }
        }
        rec[i].num=i;
    }
    sort(rec+1,rec+1+q,cmpp);
    sort(cp+1,cp+1+n,cmpp);
    int i=1;
    for(int j=i;j<=q;j++){
        while(i<=n && cp[i].pla<=rec[j].pla){
            mp[cp[i].gp*base1+cp[i].len*base2]++;
        }
        ot[rec[i].num]=mp[rec[i].gp*base1+rec[i].len*base2];
    }
    for(int i=1;i<=q;i++) cout<<ot[i]<<" ";
}

signed main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        s[i][0]=" "+s[i][0],s[i][1]=" "+s[i][1];
    }
    if(n>100 || q>100){
        solve();
        return 0;
    }
    while(q--){
        int ans=0;
        cin>>tt>>t;
        tt=" "+tt,t=" "+t;
        for(int i=1;i<=n;i++){
            ans+=cmp(tt,s[i][0],s[i][1]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
