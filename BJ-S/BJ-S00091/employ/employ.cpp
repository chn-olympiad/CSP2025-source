#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int ny[510],f[510],n,m,a[510],c[510];
long long sum;
string s;
int C(int a,int b){
    return ((f[a]*ny[a-b]%mod)*(f[a]*ny[b]%mod))%mod;
}int A(int a,int b){
    return f[a]*ny[a-b]%mod;
}
int qpow(int a,int b){
    long long cnt=a,qp=0;
    while(b>0){
        if(b&1)qp=(qp+cnt)%mod;
        b>>=1;
        cnt=(cnt*cnt)%mod;
    }return qp;
}
void Init(){
    f[0]=1;
    for(int i=1;i<=n;i++){
        f[i]=(f[i-1]*i)%mod;
        ny[i]=qpow(f[i],mod-2);
    }
}void zero_zero(){
    int k=0,peo=n-c[0];
    for(int i=0;i<n;){
        int id=i;
        while(s[i]=='1'){
            i++;
        }if(id!=i){
            sum+=A(peo,id-i);
            k++;
            peo=peo-c[k];
        }int id1=i;
        while(s[i]=='0'){
            i++;
        }if(id1!=i){
            sum+=A(n-peo,id-i);
        }
    }
}
void solve(){
    cin>>n>>m>>s;
    Init();
    int fictionstr=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        fictionstr+=s[i-1]-48;
        c[a[i]]++;
    }if(n-c[0]<m){
        cout<<0;
    }else if(fictionstr<m){
        cout<<0;
    }else if(c[1]==n){
        for(int i=0;i<m;i++){
            if(s[i]=='0'){
                cout<<0;
                return;
            }
        }cout<<f[n];
    }else if(c[0]==0){
        zero_zero();
        cout<<sum;
    }
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
