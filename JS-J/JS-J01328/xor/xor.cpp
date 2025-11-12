#include<bits/stdc++.h>
using namespace std;
struct h{
    int p,q,l;
};
bool cmp(h x,h y){
    return x.l>y.l;
}
bool b[500010];
int n,cnt,ans;
long long a,s[500010],flag[500010],k;
h _o[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a;
        s[i]=s[i-1]^a;
        flag[++cnt]=s[i]^k;
        for(int j=1;j<=cnt;j++){
            if(s[i]==flag[j]){
                _o[cnt].p=j;
                _o[cnt].q=i;
                _o[cnt].l=i-j;
            }
        }
        if(s[i]==k){
            _o[cnt].p=1;
            _o[cnt].q=i;
            _o[cnt].l=i;
        }
    }
    sort(_o+1,_o+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        for(int j=_o[i].p+1;j<=_o[i].q;j++){
            if(b[j]){
                ans--;
                for(int k=j-1;k>_o[i].p;k--){
                    b[k]=0;
                }
                break;
            }
            b[j]=1;
        }
        if(_o[i].l==0){
            break;
        }
        ans++;
    }
    cout<<ans;
    return 0;
}
