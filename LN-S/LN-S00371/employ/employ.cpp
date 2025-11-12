#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,p[15],c[15];
char s[15];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) p[i]=i;
    do{
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='1'&&i-cnt-1<c[p[i]]) cnt++;
        }
        if(cnt>=m) ans++;
    }while(next_permutation(p+1,p+n+1));
    printf("%d",ans);
    return 0;
}
//I Love CCF.
