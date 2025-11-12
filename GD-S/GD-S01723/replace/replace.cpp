#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
const int N=2e5+10;
string s[N][2];
int n,q;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    n=read(),q=read();
    for(int i=1;i<=n;i++)
        cin>>s[i][0]>>s[i][1];
    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        int ans=0;
        for(int i=1;i<=n;i++){
            int id=t1.find(s[i][0]);
            if(id==-1)continue;
            string str=t1.substr(0,id)+s[i][1]+t1.substr(id+s[i][1].size());
            if(str==t2)ans++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
