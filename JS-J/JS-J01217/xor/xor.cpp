#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],x[N],t[N],cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x[i]=a[i]^x[i-1];
        t[i]=x[i]^k;
    }
    //cout<<x[0]<<endl;
    //a[i]^a[i+1]^...^a[j]=x[j]^x[i-1];
    int lst=0;
    for(int r=1;r<=n;r++){
        for(int l=lst+1;l<=r;l++){
            if(t[r]==x[l-1]){
                //cout<<l<<' '<<r<<' '<<(x[r]^x[l-1])<<endl;
                cnt++;
                lst=r;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}