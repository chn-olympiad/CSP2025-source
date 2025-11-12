#include<bits/stdc++.h>
// #define int long long
using namespace std;
const int N=1e5+5;
string s[N][3],a,b;
int len[N][3],nxt[10005][10005];

inline int read(){
    int a=1,b=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') a=-a;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        b=(b<<1)+(b<<3)+(ch^48);
        ch=getchar();
    }
    return a*b;
}

inline void write(int x){
    if(x>9) write(x/10);
    putchar(x%10+'0');
}


signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    // int n=read(),q=read();
    // vector<vector<int> >nxt;
    for(int i=1;i<=n;i++){
        cin>>s[i][1];
        cin>>s[i][2];
        len[i][1]=s[i][1].size();
        len[i][2]=s[i][2].size();
        s[i][1]=' '+s[i][1],s[i][2]=' '+s[i][2];
        // return 0;
        nxt[i][1]=0;
        for(int ii=2,j=0;ii<=len[i][1];ii++){
            while(s[i][1][j+1]!=s[i][1][ii]&&j) j=nxt[i][j];
            if(s[i][1][j+1]==s[i][1][ii]) j++;
            nxt[i][ii]=j; 
        }
    }        
    while(q--){
        cin>>a>>b;
        // return 0;
        int x=a.size(),y=b.size();
        a=' '+a,b=' '+b;
        int ans=0;
        for(int k=1;k<=n;k++){
                // if(k==3) return 0;
            for(int i=1,j=0;i<=x;i++){
                while(s[k][1][j+1]!=a[i]&&j) j=nxt[k][j];
                // if(k==2) cout<<i<<endl;
                if(s[k][1][j+1]==a[i]) j++;
                // if(k==3&&i==4) cout<<j<<" "<<len[k][1]<<endl;
                if(j==len[k][1]){
                    // if(k==3) cout<<"!!!";
                    int l1=i-len[k][1]+1,r1=i;
                    string tmp1="";
                    if(l1!=1) tmp1=a.substr(1,l1-1)+s[k][2].substr(1,len[k][2]);
                    else tmp1=s[k][2].substr(1,len[k][2]);
                    // string tmp1=a.substr(1,l1-1)+s[k][1].substr(1,len[k][1]);
                    if(r1!=x) tmp1=tmp1+a.substr(r1+1,x);
                    tmp1=' '+tmp1;
                    // cout<<tmp1<<endl<<<<endl;;
                    // string tmp2="";
                    // if(l1!=1) tmp2=b.substr(1,l1-1)+s[k][2].substr(1,len[k][2]);
                    // else tmp2=s[k][2].substr(1,len[k][2]);
                    // cout<<tmp2<<endl;
                    // string tmp1=a.substr(1,l1-1)+s[k][1].substr(1,len[k][1]);
                    // cout<<tmp1<<endl;
                    // cout<<tmp2<<endl;
                    // if(r1!=x) tmp2=tmp2+b.substr(r1+1,y);
                    if(tmp1==b) {ans++;break;}

                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}