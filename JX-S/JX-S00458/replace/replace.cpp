#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
string as[200005],bs[200005];
int n,q,ans;
void solve(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) cin>>as[i]>>bs[i];
    for(int i=1;i<=q;i++){
        string s,t;cin>>s>>t;
        ans=0;
        for(int j=1;j<=n;j++){
            int pos=-1;
            while(1){
                pos=s.find(as[j],pos+1);
                if(pos!=-1){
                    string tmp=s;
                    for(int k=pos;as[j][k-pos];k++) tmp[k]=bs[j][k-pos];
                    if(tmp==t) ans++;
                }else break;
            }
        }
        printf("%d\n",ans);
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int T=1;//scanf("%d",&T);
    while(T--) solve();
    return 0;
}
//The string problem is so evil that I only passed Example 1 and 2.
//I have tried to learn KMP many times, but I couldn't understand the algorithm!!!
//Now I want to be DESTRUCTED. There were only less than 8 pts I could get.
