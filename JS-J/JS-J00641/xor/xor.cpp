#include<bits/stdc++.h>
using namespace std;
long long wc[100050],t[100050];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    bool flag=true;
    long long n,m,maxn=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>wc[i];
        t[wc[i]]++;
        if(wc[i]!=0&&wc[i]!=1)flag=false;
    }
    if(flag){
        if(t[0]>0){
            if(m==0)cout<<t[1]/2;
            else cout<<t[1];
        }
        else{
            cout<<t[1]/2;
        }
        return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            long long cw=0,tmp=0;
            for(int j=i;j<=n;j++){
                cw=cw^wc[j];
                if(cw==m){
                    cw=0;
                    tmp++;
                }
            }
            maxn=max(maxn,tmp);
        }
    }
    cout<<maxn;
    return 0;
}
