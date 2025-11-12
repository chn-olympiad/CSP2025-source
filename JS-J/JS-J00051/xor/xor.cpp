#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500001];
int n,k;
int Xor(int a,int b){
    int s=0;
    if(b>a)swap(a,b);
    while(a){
        if(a%2==1&&b%2==1)s+=0;
        else s+=1;
        s<<1;
        a>>1,b>>1;
    }
    return s/2;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1)cnt++;
    }
    if(cnt==n&&k==0){
        cout<<n/2;
    }
    else{
        cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]!=1||a[i+1]!=1){
                cnt++;
                i++;
            }
        }
        cout<<cnt;
    }

    return 0;
}
