#include <bits/stdc++.h>
#define N 200002
#define ull unsigned long long
using namespace std;
const ull B=131;
int n,q,len1[N],len2[N],a[N],b[N];
ull hsh1[N],pw[N];
vector<ull> hsh2[N];
string s[N][2],t[N][2],s2[N][2],t2[N][2];
bool flg[N];
ull query(int i,int l,int r){
    if(l==0)  return hsh2[i][r];
    else  return hsh2[i][r]-hsh2[i][l-1]*pw[r-l+1];
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>q;
    pw[0]=1;
    for(int i=1;i<=N-2;i++)  pw[i]=pw[i-1]*B;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        len1[i]=s[i][0].length();
        int l=len1[i],r=-1;
        for(int j=0;j<len1[i];j++){
            hsh1[i]=hsh1[i]*B+s[i][0][j];
            if(s[i][0][j]!=s[i][1][j]){
                l=min(l,j);
                r=max(r,j);
            }
        }
        a[i]=l;
        for(int j=l;j<=r;j++){
            s2[i][0]+=s[i][0][j];
            s2[i][1]+=s[i][1][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>t[i][0]>>t[i][1];
        if(t[i][0].length()!=t[i][1].length()){flg[i]=1;continue;}
        len2[i]=t[i][0].length();
        hsh2[i].reserve(len2[i]+1);
        int l=len2[i],r=-1;
        for(int j=0;j<len2[i];j++){
            if(j)  hsh2[i][j]=hsh2[i][j-1]*B+t[i][0][j];
            else  hsh2[i][j]=t[i][0][j];
            // cout<<i<<", "<<j<<": "<<hsh2[i][j]<<"\n";
            if(t[i][0][j]!=t[i][1][j]){
                l=min(l,j);
                r=max(r,j);
            }
        }
        b[i]=l;
        for(int j=l;j<=r;j++){
            t2[i][0]+=t[i][0][j];
            t2[i][1]+=t[i][1][j];
        }
    }
    for(int i=1;i<=q;i++){
        int ans=0;
        for(int j=1;j<=n;j++){
            // cout<<s2[j][0]<<" "<<t2[i][0]<<" "<<s2[j][1]<<" "<<t2[j][1]<<"\n";
            if(s2[j][0]!=t2[i][0]||s2[j][1]!=t2[i][1])  continue;
            // cout<<j<<" ";
            // cout<<i<<" "<<b[i]-a[j]<<", "<<b[i]-a[j]+len1[j]-1<<" "<<query(i,b[i]-a[j],b[i]-a[j]+len1[j]-1)<<"; "<<hsh1[j]<<"\n";
            if(query(i,b[i]-a[j],b[i]-a[j]+len1[j]-1)==hsh1[j])  ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}