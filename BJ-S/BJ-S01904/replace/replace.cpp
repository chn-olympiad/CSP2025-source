#include<bits/stdc++.h>
using namespace std;
int T,n,nxt[1000001][27],num[1000001],cnt=1,now;
struct TT{
    string s1,s2;
}a[200005],b[200005];
struct TTT{
    int s1,s2,l1,l2;
};
void insert(string s){
    int p=1;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(!nxt[p][c-'a'])nxt[p][c-'a']=++cnt;
        p=nxt[p][c-'a'];
    }
    num[p]++;
}
int query(string s){
    int p=1;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(!nxt[p][c-'a'])return 0;
        p=nxt[p][c-'a'];
    }
    //cout<<p<<" ask"<<endl;
    return num[p];
}
bool cmp(TT x,TT y){
    if(x.s1!=y.s1)return x.s1<y.s1;
    return x.s2<y.s2;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>T;
    for(int i=1;i<=n;i++){
        cin>>a[i].s1>>a[i].s2;
    }
    sort(a+1,a+n+1,cmp);
    // for(int i=1;i<=n;i++){
    //     if(a[i].s1!=a[i-1].s1||a[i].s2!=a[i-1].s2){
    //         b[++now]=a[i];
    //     }
    //     //cout<<a[now].s1<<a[now].s2<<endl;
    // }
    // for(int i=1;i<=now;i++){
    //     a[i]=b[i];
    // }
    // n=now;
    for(int i=1;i<=n;i++){
        string s1="",s2="";
        int l=0,r=a[i].s1.length()-1;
        while(l<a[i].s1.length()&&a[i].s1[l]==a[i].s2[l]){
            l++;
        }
        while(r>=0&&a[i].s1[r]==a[i].s2[r]){
            r--;
        }
        //cout<<l<<" "<<r<<" "<<a[i].s1<<" "<<a[i].s2<<endl;
        if(l>r){
            continue;
        }
        for(int j=l;j<=r;j++){
            s1+=a[i].s1[j],s2+=a[i].s2[j];
        }
        //cout<<a[i].s1<<" "<<a[i].s2<<" "<<l<<" "<<r<<endl;
        a[i].s1=s1+char('a'+26)+s2;
        //cout<<a[i].s1<<endl;
        insert(a[i].s1);
        s1="",s2="";
    }
    while(T--){
        string s1,s2,ss1="",ss2="";
        cin>>s1>>s2;
        if(s1.length()!=s2.length()){
            cout<<0<<endl;
            continue;
        }
        int l=0,r=s1.length()-1;
        while(l<s1.length()&&s1[l]==s2[l]){
            l++;
        }
        while(r>=0&&s1[r]==s2[r]){
            r--;
        }
        for(int j=l;j<=r;j++){
            ss1+=s1[j],ss2+=s2[j];
        }
        ss1=ss1+char('a'+26)+ss2;
        //cout<<ss1<<" ask"<<endl;
        cout<<query(ss1)<<endl;
    }
    return 0;
}//g++ -Wall -std=c++14 -fsanitize=address,undefined,leak -O2 3.cpp -o 3
//time ./3