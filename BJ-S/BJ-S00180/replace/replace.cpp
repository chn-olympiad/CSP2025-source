#include<bits/stdc++.h>
using namespace std;
int n,q,start,finish,l;
string ss1,ss2,x,y;
vector<int>v1[26],v2[26];
vector<string>v;
set<vector<string> >s;
struct S{
    string s1,s2;
}a[200005];
bool cmp(S x,S y){
    if(x.s1.length()==y.s1.length())return x.s1<y.s1;
    else return x.s1.length()<y.s1.length();
}int conx(string str){
    for(auto i:v1[str[0]-'a'])if(x.substr(i,str.length())==str)return i;
    return -1;
}int cony(string str){
    for(auto i:v2[str[0]-'a'])if(y.substr(i,str.length())==str)return i;
    return -1;
}int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>ss1>>ss2;
        v.clear();
        v.push_back(ss1);
        v.push_back(ss2);
        s.insert(v);
    }int iii=0;
    for(auto i:s){
        a[++iii].s1=i[0];
        a[iii].s2=i[1];
    }sort(a+1,a+n+1,cmp);
    while(q--){
        cin>>x>>y;
        if(x.length()!=y.length()){
            cout<<0<<"\n";
            continue;
        }for(int i=0;i<x.length();i++){
            v1[x[i]-'a'].push_back(i);
            v2[y[i]-'a'].push_back(i);
        }for(int i=0;i<x.length();i++){
            if(x[i]!=y[i]){
                start=i;
                break;
        }}for(int i=x.length()-1;i>=0;i--){
            if(x[i]!=y[i]){
                finish=i;
                break;
        }}l=finish-start+1;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i].s1.length()<l||a[i].s1.length()>x.length())continue;
            if(conx(a[i].s1)==-1||cony(a[i].s2)==-1)continue;
            if(conx(a[i].s1)!=cony(a[i].s2))continue;
            ans++;
        }cout<<ans<<"\n";
    }
    return 0;
}
