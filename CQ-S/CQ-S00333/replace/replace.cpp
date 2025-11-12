#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=2e5+5,M=5e6+5;
int n,q,len[N];ull ha1[M][3],ha2[M][3],h1[N],h2[N],pw[M];
string s[N][2];
vector<int> nxt[N];
// vector<ull> ha[N];
ull get_ha(int f,int l,int r){
    return ha2[r][f]-ha2[l-1][f]*pw[r-l+1];
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        s[i][0]=" "+s[i][0];
        len[i]=s[i][0].size();
        nxt[i].resize(len[i]+5);
        for(int k=2,j=0;k<=len[i];k++){
            while(j&&s[i][0][k]!=s[i][0][j+1])j=nxt[i][j];
            if(s[i][0][k]==s[i][0][j+1])j++;
            nxt[i][k]=j;
        }
        ull ha_1[N],ha_2[N];
        // memset(ha_1,0,sizeof ha_1);
        ha_1[0]=ha_2[0]=0;
        for(int j=1;j<=len[i];j++){
            ha_1[j]=ha_1[j-1]*131+s[i][1][j];
            ha_2[j]=ha_2[j-1]*1331+ha_1[j];
        }
        h1[i]=ha_2[len[i]];
    }
    pw[0]=1;
    for(int i=1;i<M;i++){
        pw[i]=pw[i-1]*1331;
    }
    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        int m=t1.size();
        t1=" "+t1;t2=" "+t2;
        for(int i=1;i<=m;i++){
            ha1[i][1]=ha1[i-1][1]*131+t1[i];
            ha2[i][1]=ha2[i-1][1]*1331+ha1[i][1];
            ha1[i][2]=ha1[i-1][2]*131+t2[i];
            ha2[i][2]=ha2[i-1][2]*1331+ha1[i][2];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int k=1,j=0;k<=m;k++){
                while(j&&s[i][0][j+1]!=t1[k])j=nxt[i][j];
                if(s[i][0][j+1]==t1[k])j++;
                if(j==len[i]){
                    // cout<<k-j+1<<"\n";
                    // if(get_ha(1,1,k-j)==get_ha(2,1,k-j)&&get_ha(1,k+1,m)==get_ha(2,k+1,m)&&get_ha(1,k-j+1,k)==h1[i])ans++;
                    string tmp=t1.substr(1,k-j)+s[i][1]+t1.substr(k+1,m-k);
                    if(tmp==t2)ans++;
                    j=nxt[i][j];
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
AC 自动机？？？

特殊性质 A:
直接用 KMP 跑就行，再用哈希判断是否相同
特殊性质 B：

*/