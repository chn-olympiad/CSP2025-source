#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int c=0,x=1;
    char ch=getchar();

    while(ch<'0'||ch>'9'){
        if(ch=='-'){
            x=-1;
        }
        ch=getchar();
    }

    while(ch>='0'&&ch<='9'){
        c=c*10+ch-'0';
        ch=getchar();
    }

    return c*x;
}

int n,q;
int hash1[300005],hash2[300005];

int f1(string s){
    int ans=0;
    for(int i=0;i<s.length();i++){
        ans=ans*97+i;
    }
}

int f2(string s){
    int ans=0;
    for(int i=0;i<s.length();i++){
        ans=ans*101+i;
    }
}

bool same(string a,string b){
    return f1(a)==f1(b)&&f2(a)==f2(b);
}

string s[200005][2];
string s2[200005][2];
int s1[200005][2];
string t0,t1;

signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    n=read(),q=read();

    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        int ma=0,mi=s[i][0].length();
        for(int j=0;j<s[i][0].length();j++){
            if(s[i][0][j]!=s[i][1][j]){
                ma=max(ma,j);
                mi=min(mi,j);
            }
        }
        s1[i][0]=mi,s1[i][1]=ma;
        for(int j=mi;j<=ma;j++){
            s2[i][0]+=s[i][0][j];
            s2[i][1]+=s[i][1][j];
        }
    }

    while(q--){
        int ans=0;
        cin>>t0>>t1;
        int ma=0,mi=t0.length();
        for(int j=0;j<t0.length();j++){
            if(t0[j]!=t1[j]){
                ma=max(ma,j);
                mi=min(mi,j);
            }
        }
        string t00,t01;
        for(int i=mi;i<=ma;i++){
            t00+=t0[i];
            t01+=t1[i];
        }
        for(int i=1;i<=n;i++){
            if(t00==s2[i][0]&&t01==s2[i][1]){
                if(t0.substr(mi-(s1[i][0]),ma+s[i][0].length()-s1[i][1])==s[i][0]){ans++;}
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
