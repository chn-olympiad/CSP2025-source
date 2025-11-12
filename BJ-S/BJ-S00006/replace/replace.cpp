#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define int long long
using namespace std;
const int N=2e5+5;
int pp1[N],pp2[N];
int n,q;
string s[N][2];
string st[N];
int ls[N];
int f1[N],f2[N];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        int tplen=s[i][0].size();
        ls[i]=tplen;
        f1[i]=0;
        for(int j=0;j<tplen;j++){
            if(s[i][0][j]==s[i][1][j])f1[i]++;
            else break;
        }
        f2[i]=tplen-1;
        for(int j=tplen-1;j>=0;j--){
            if(s[i][0][j]==s[i][1][j])f2[i]--;
            else break;
        }
        string tp1="",tp2="";
        for(int j=f1[i];j<=f2[i];j++){
            tp1=tp1+s[i][0][j];
            tp2=tp2+s[i][1][j];
        }
        st[i]=tp1+tp2;
    }
    while(q--){
        string a,b;
        cin>>a>>b;
        int len=a.size();
        if(len!=b.size()){
            cout<<0<<endl;
            continue;
        }
        a='?'+a,b='?'+b;
        int tf1=0,tf2=0;
        bool putf=false;
        for(int i=1;i<=len;i++){
            if(tf2&&a[i]!=b[i]&&a[i-1]==b[i-1])putf=true;
            if(a[i-1]==b[i-1]&&a[i]!=b[i])tf1=i;
            if(a[i]!=b[i])tf2=i;
        }
        if(putf){
            cout<<0<<endl;
            continue;
        }
        string dif1="",dif2="";
        for(int i=1;i<=len;i++){
            if(a[i]!=b[i])dif1=dif1+a[i],dif2=dif2+b[i];
        }
        string dif=dif1+dif2;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(st[i]==dif&&ls[i]<=len){
                bool fl=false;
                if(tf1-f1[i]<=0)continue;
                string tmp=a;
              //  cout<<i<<' '<<tf1-f1[i]<<endl;
                tmp=tmp.substr(tf1-f1[i],ls[i]);
              //  cout<<tmp<<' '<<s[i][0]<<endl;
                if(tmp==s[i][0])ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
