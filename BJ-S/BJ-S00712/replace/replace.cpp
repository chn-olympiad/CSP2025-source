#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,L=5e6+5,B=131;
typedef unsigned int ui;
void kmp(string s,int *a){
    int n=s.size();
    a[0]=0;
    for(int i=1,j;i<n;i++){
        j=a[i-1];
        while(s[j]!=s[i]&&j)j=a[j-1];
        if(s[j]==s[i])j++;
        a[i]=j;
    }
}
int a[L],b[L],ans;
string s[N],s2[N];
void getans(string al,string bl,int j,int l,int r){
    al=s[j]+"#"+al;
    bl=s2[j]+"#"+bl;
    kmp(al,a);
    kmp(bl,b);
    int st=s[j].size();
    for(int i=st+r;i<al.size()&&i<=l+st+st;i++){
        if(a[i]==s[j].size()&&b[i]==s[j].size()){
            ans++;
            //  cout<<s[j]<<' '<<s2[j]<<'\n';
            //cout<<i-st-st+1<<' '<<i-st+1<<'\n';
        }
    }
}
string q1,q2;
int n,q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>s2[i];
    }
    int k=0;
    while(q--){
        cin>>q1>>q2;
        if(q1.size()!=q2.size()){
            cout<<"0\n";
            continue;
        }
        int l=q1.size();
        int fs=0,bs=l;ans=0;
        while(q1[fs]==q2[fs]&&fs<l)fs++;
        while(q1[bs-1]==q2[bs-1]&&bs)bs--;
       // cout<<fs<<" "<<bs<<'\n';
        for(int i=1;i<=n;i++){
            getans(q1,q2,i,fs,bs);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
