#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
string s;
int c[100];
int p[100];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)p[i]=i;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++)cin>>c[i];
    do{
        int cnt=0,cntf=0;
        for(int i=1;i<=n;i++){
            int x=p[i];
            if(cntf>=c[x]){
                cntf++;
                continue;
            }
            if(s[i]=='0'){
                cntf++;
                continue;
            }
            cnt++;
        }
        if(cnt>=m)ans++;
    }while(next_permutation(p+1,p+1+n));
    cout<<ans<<endl;
    return 0;
}
