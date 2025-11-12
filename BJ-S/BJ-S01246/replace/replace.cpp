#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,B=131;
unsigned long long h[N][2],pw[N],g[2][N],len[N];
unsigned long long get2(int i,int l,int r){
    return g[i][r]-g[i][l-1]*pw[r-l+1];
}
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    pw[0]=1;
    for(int i=1;i<=N-5;i++)pw[i]=pw[i-1]*B;
    for(int k=1;k<=n;k++){
        string s[2];
        for(int i=0;i<2;i++){
            cin>>s[i];
            int m=len[k]=s[i].size();
            s[i]=' '+s[i];
            for(int j=1;j<=m;j++){
                h[k][i]=h[k][i]*B+s[i][j];
            }
        }
    }
    for(int k=1;k<=q;k++){
        string t[2];
        int ans=0;
        for(int i=0;i<2;i++){
            cin>>t[i];
            int m=t[i].size();
            t[i]=' '+t[i];
            for(int j=1;j<=m;j++){
                g[i][j]=g[i][j-1]*B+t[i][j];
            }
        }
        if(t[0].size()!=t[1].size()){
            cout<<0<<endl;
            continue;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j+len[i]-1<=t[0].size()-1;j++){
                if(get2(0,j,j+len[i]-1)==h[i][0]&&get2(1,j,j+len[i]-1)==h[i][1]&&get2(0,1,j-1)==get2(1,1,j-1)&&get2(0,j+len[i],t[0].size()-1)==get2(1,j+len[i],t[0].size()-1))ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
