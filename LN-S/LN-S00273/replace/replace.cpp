#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,M=2e6+5;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
int n,q;
string s[N],t[N],t1,t2;
inline int find(string a,string b){
    for(int i=0;i+b.size()-1<a.size();i++){
        bool flag=1;
        for(int j=i;j<=i+b.size()-1;j++){
            if(a[j]!=b[j-i]){
                flag=0;
                break;
            }
        }
        if(flag) return i;
    }
    return -1;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>t[i];
    }
    while(q--){
        cin>>t1>>t2;
        int cnt=0;
        for(int i=1;i<=n;i++){
            int st=find(t1,s[i]);
            if(st==-1) continue;
            if(st!=0){
                string x=t1.substr(0,st)+t[i];
                // cout<<t1.substr(0,st)<<'\n';
                if(st!=t1.size()-1) x=x+t1.substr(st+t[i].size(),t1.size());
                // cout<<x<<'\n';
                if(x==t2) cnt++;
            }
            else{
                string x=t[i];
                if(st!=t1.size()-1) x=x+t1.substr(st+t[i].size(),t1.size());
                // cout<<x<<'\n';
                if(x==t2) cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}