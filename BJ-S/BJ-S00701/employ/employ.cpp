#include<bits/stdc++.h>
using namespace std;
#define int long long
int maxn=998244353,n,m,a[1005],A=1,sum=0,cnt=1,tot=0,go=0,cct=0;
string b;
signed main(){
    cin>>n>>m;
    b+=".";
    cin>>b;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(b[i]=='0'){
            A=0;
        }
        else{
            cct+=1;
        }
    }
    if(cct<m){
        cout<<0;
        return 0;
    }
    if(A){
        if(a[1]){
            ++tot;
        }
        else{
            go+=1;
        }
        for(int i=2;i<=n;i++){
            if(a[i]>go){
                cnt*=2;
                cnt%=maxn;
                ++tot;
            }
            else{
                go++;
            }
        }
        if(tot>=m){
            cout<<cnt;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    return 0;
}