#include<bits/stdc++.h>
using namespace std;
const int N=5001;
int n,a[N];
bool f1=true,f2=true;
int fpow(int x){
    int ans=1;
    for(int i=1;i<=x;i++) ans=ans*2%998244353;
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>100) f1=false;
        if(a[i]>1) f2=false;
    }
    if(n<=20){//Test 1-10
        int t[N],s[N],ans=0;
        for(int i=0;i<(1<<n);i++){
            int tmp=i,p=-1,q=0;
            memset(t,0,sizeof(t));
            memset(s,0,sizeof(t));
            while(tmp){
                t[n-(++p)]=tmp%2;
                tmp>>=1;
            }
            for(int i=1;i<=n;i++) if(t[i]) s[++q]=a[i];
            int ssum=0,smax=0;
            for(int i=1;i<=q;i++){
                ssum+=s[i];
                smax=max(smax,s[i]);
            }
            if(ssum>smax*2) ans++;
        }
        cout<<ans;
        return 0;
    }
    if(n<=500&&f1){//Test 11-14
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            cout<<a[i]<<' ';
        }
    }
    if(f2){//Test 15-20
        cout<<fpow(n)-n-n*(n-1)/2-1;
        return 0;
    }
}
//expected: 64pts
