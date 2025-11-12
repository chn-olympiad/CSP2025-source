#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n;
string s1[N],s2[N];
inline void work1(){
    string t1,t2;
    cin>>t1>>t2;
    int sz=t1.size();
    int l=-1,r;
    for (int i=0;i<sz;i++){
        if (t1[i]!=t2[i]){
            r=i;
            if (l==-1) l=i;
        }
    }
    if (l==-1){
        int res=0;
        for (int i=0;i<sz;i++){
            for (int k=1;i+k-1<sz;k++){
                string str=t1.substr(i,k);
                for (int j=1;j<=n;j++){
                    if (str==s1[j]&&str==s2[j]) res++;
                }
            }
        }
        cout<<res<<'\n';
        return;
    }
    int res=0;
    for (int i=1;i<=n;i++){
        int ssz=s1[i].size();
        for (int j=max(0,r-ssz+1);j<=l&&j+ssz-1<sz;j++){
            string str=t1.substr(j,ssz);
            if (str!=s1[i]) continue;
            if (s2[i]==t2.substr(j,ssz)) res++;
        }
    }
    cout<<res<<'\n';
}
struct node{
    int l,r,mv;
    friend bool operator <(const node &a,const node &b){
        return a.mv<b.mv;
    }
} a[N];
int boundl(int x){
    int l=1,r=n;
    int res;
    while (l<=r){
        int mid=(l+r)>>1;
        if (a[mid].mv<x){
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return res+1;
}
int boundr(int x){
    int l=1,r=n;
    int res;
    while (l<=r){
        int mid=(l+r)>>1;
        if (a[mid].mv>x){
            res=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return res-1;
}
bool flag=0;
inline void work2(){
    if (!flag){
        for (int i=1;i<=n;i++){
            int l,r;
            for (int j=0;j<s1[i].size();j++){
                if (s1[i][j]=='b'){
                    a[i]={j,s1[i].size()-1-j,-1};
                    l=j;
                }
                if (s2[i][j]=='b'){
                    r=j;
                }
            }
        }
        flag=1;
    }
    string t1,t2;
    cin>>t1>>t2;
    int l;
    for (int i=0;i<t1.size();i++){
        if (t1[i]=='b') l=i;
    }
    int res=0;
    for (int i=1;i<=n;i++){
        int sz=s1[i].size();
        if (l-a[i].l<0) continue;
        if (t2.substr(l-a[i].l,sz)==s2[i]) res++;
    }
    cout<<res<<'\n';
    return;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int q;
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    while (q--){
        if (n<=100) work1();
        else work2();
    }
    return 0;
}
