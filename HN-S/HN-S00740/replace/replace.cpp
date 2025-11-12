#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005];
int n,q;
int a[200005],b[200005],len[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        len[i]=s1[i].length();
        for(int j=0;j<len[i];j++){
            if(s1[i][j]=='b') a[i]=j;
            if(s2[i][j]=='b') b[i]=j;
        }
    }
    while(q--){
        string x,y;
        cin>>x>>y;
        int L=x.length(),t,p,ans=0;
        for(int i=0;i<L;i++){
            if(x[i]=='b') t=i;
            if(y[i]=='b') p=i;
        }
        for(int i=1;i<=n;i++){
            if((b[i]-a[i]==p-t)&&t>=a[i]&&(L-t>=len[i]-a[i])){
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}