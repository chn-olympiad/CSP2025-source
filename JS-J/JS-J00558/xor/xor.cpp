#include <bits/stdc++.h>
using namespace std;
typedef long long  LL;
const int N=5e5+14;
LL a[N],ans,b[N],c[N];
bool f[N];
int n,k;
LL yhh(LL a,LL  b){
    LL m=max(a,b),t=1,anns=0;
    while(m){
        if(a%2==b%2)anns+=0;
        else anns+=pow(2,t-1);
        a/=2;b/=2;m/=2;
        t++;
    }
    return anns;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    bool Me163=true,Me262A=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(Me163&&a[i]!=1)Me163=false;
        if(Me262A&&a[i]!=0&&a[i]!=1)Me262A=false;
    }
    if(k==0&&Me163){
        cout<<n;return 0;
    }
    else if(k<=1&&Me262A){
        for(int i=1;i<=n-1;){
                if(a[i]==k){
                    ans++;
                    i++;
                    continue;
                }
            if(yhh(a[i],a[i+1])==k){
                ans++;i+=2;
            }else i++;
        }
        if(n==1){
            if(a[1]==k)ans++;
        }
    }else{
        //c[1]=a[1];
        //for(int i=1;i<=n;i++)c[i]=yhh(c[i-1],a[i]);
        b[1]=a[1];
        if(b[1]==k){
            ans++;f[1]=true;
        }
        for(int i=2;i<=n;i++){
            if(!f[i-1]){
                b[i]=yhh(b[i-1],a[i]);
            }else b[i]=a[i];
            if(b[i]==k){
                ans++;f[i]=true;
            }
            //cout<<ans<<endl;
            if(!f[i-1]&&!f[i]){
                for(int j=i-1;!f[j]&&j;j--){
                    if(yhh(b[i],b[j])==k){
                        ans++;
                        f[i]=true;
                        b[i]=k;
                        break;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
