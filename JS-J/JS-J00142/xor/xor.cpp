#include <bits/stdc++.h>
using namespace std;
const int N=2e6+7;
int n,k,a[N]={0};
int xorr(int a,int b){
    if(a>b)swap(a,b);
    string x="",y="",z="";
    int re=0;
    while(a){
        x+=(a%2+'0');
        a/=2;
    }
    while(b){
        y+=(b%2+'0');
        b/=2;
    }
    int m=y.size();
    int q=m-x.size();
    for(int i=m-1;i>=0;i--){
        if(y[i]!=x[i-q])z+="1";
        else z+="0";
    }
    for(int i=z.size()-1;i>=0;i--){
        re*=2;
        re+=z[i]-'0';
    }
    return re;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    int w;
    for(int i=1;i<=n;i++){
        cin>>w;

        a[i]=xorr(a[i-1],w);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(k==xorr(a[i],a[j]))cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
