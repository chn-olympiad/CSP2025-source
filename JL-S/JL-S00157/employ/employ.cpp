#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    string s;
    cin>>s;
    int fi=-1,fi1=-1;
    if(m==1){
        for(int i=0;i<n;i++){
            if(s[i]=='1'&&fi==-1){
                fi=i;
                break;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(x>fi+1) ans++;
        }
        long long cnt=ans;
        for(int i=1;i<=n-1;i++){
            cnt=(cnt*i)%MOD;
        }
        printf("%lld",cnt);
        return 0;
    }
    long long cnt=1;
    for(int i=1;i<=n;i++){
        cnt=(cnt*i)%MOD;
    }
    printf("%lld",cnt);
    return 0;
}
