#include<iostream>
#include<algorithm>
#include<string>
#include<ios>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;
vector<string> a[2];
int n,m;
struct mv{
    int le,ri;
};
map<int,vector<mv> > x;
/*
void solve1(){
    string a1,a2;
    cin>>a1>>a2;
    int len=a1.size(),l2=a2.size();
    if(len!=l2){
        cout<<"0\n";
        return ;
    }
    int l=-1,r;
    for(int i=0;i<len;i++){
        if(a1[i]!=a2[i]){
            r=i;
            if(l==-1) l=i;
        }
    }
    for(int i=0;i<a[0].size();i++){
        if(a[0][i].size()<r-l+1||a[0][i].size()>len) continue;
        else{
            for(int i=max(r-a[0][i].size()-1,0);i<=min(len-a[0][i].size()+1,l);i++){

            }
        }
    }
}
*/
void solve2(){
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        string s1,s2;
        cin>>s1>>s2;

        a[0].push_back(s1);
        a[1].push_back(s2);
    }
    //if(m==1) solve1();
    if(n<=1000) solve2();
    else{
        for(int i=0;i<n;i++){
            int p1,p2;
            for(int j=0;j<a[0][i].size();j++){
                if(a[0][i][j]=='b') p1=j;
            }
            for(int j=0;j<a[1][i].size();j++){
                if(a[1][i][j]=='b') p2=j;
            }
            //cout<<i<<':'<<a[0][i].size()<<' '<<a[1][i].size()<<'\n';
            x[p2-p1].push_back({p1,a[0][i].size()-p2});
        }
        for(int i=0;i<m;i++){
            string a1,a2;
            cin>>a1>>a2;
            int p1,p2;
            for(int j=0;j<a[0][i].size();j++){
                if(a[0][i][j]=='b') p1=j;
            }
            for(int j=0;j<a[1][i].size();j++){
                if(a[1][i][j]=='b') p2=j;
            }
            if(x[p2-p1].empty()){
                cout<<"0\n";
            }
            else{
                int cnt=0;
                for(int i=0;i<x[p2-p1].size();i++){
                    if(p1-x[p2-p1][i].le>=0&&p2+x[p2-p1][i].ri<=n){
                        cnt++;
                    }
                }
                cout<<cnt<<'\n';
            }
        }
    }
    return 0;
}
