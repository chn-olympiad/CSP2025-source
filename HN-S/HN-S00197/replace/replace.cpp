#include<bits/stdc++.h>
#define fir first
#define sec second
using namespace std;
const int N=2e5+10;
int n,q,res,pre,suf,id[N][3],id1,id2;
string s[N][3],t[3];
bool B=1;
bool check(int a,int p){
    for(int i=0;i<s[p][1].size();i++){
        if(t[1][a+i]!=s[p][1][i]||t[2][a+i]!=s[p][2][i]){
            return 0;
        }
    }
    return 1;
}
void solve1(){
    res=0;
    cin>>t[1]>>t[2];
    if(t[1].size()!=t[2].size()){
        cout<<0<<endl;
        return;
    }
    pre=suf=-2;
    for(int i=0;i<t[1].size();i++){
        if(t[1][i]!=t[2][i]){
            pre=i-1;
            break;
        }
    }
    if(pre==-2)pre=t[1].size()-1;
    for(int i=t[1].size()-1;i>=0;i--){
        if(t[1][i]!=t[2][i]){
            suf=i+1;
            break;
        }
    }
    if(suf==-2)suf=0;
    for(int i=0;i<=pre+1;i++){
        for(int j=1;j<=n;j++){
            if((suf-1)-i+1>s[j][1].size()||s[j][1].size()+i-1>t[1].size())continue;
            if(check(i,j))res++;
        }
    }
    cout<<res<<endl;
}
void pr(){
    for(int i=1;i<=n;i++){
        for(int j=0;j<s[i][1].size();j++){
            if(s[i][1][j]=='b'){
                id[i][1]=j+1;
            }
            if(s[i][2][j]=='b'){
                id[i][2]=j+1;
            }
        }
    }
}
void solve2(){
    res=0;
    cin>>t[1]>>t[2];
    if(t[1].size()!=t[2].size()){
        cout<<0<<endl;
        return;
    }
    for(int i=0;i<t[1].size();i++){
        if(t[1][i]=='b'){
            id1=i+1;
            break;
        }
    }
    for(int i=0;i<t[2].size();i++){
        if(t[2][i]=='b'){
            id2=i+1;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(id[i][1]>id1||s[i][1].size()-id[i][2]>t[1].size()-id2){
            continue;
        }
        if(id[i][2]-id[i][1]!=id2-id1){
            continue;
        }
        res++;
    }
    cout<<res<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
        if(!B)continue;
        for(auto j:s[i][1]){
            if(j!='a'&&j!='b')B=0;
        }
    }
    if(B)pr();
    for(int i=1;i<=q;i++){
        if(B)solve2();
        else solve1();
    }
    return 0;
}