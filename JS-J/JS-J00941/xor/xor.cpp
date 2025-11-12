#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,k,a[N],id,f,sum,f1,cnt,f2;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) f=1;
        if(a[i]==1) sum++;
        if(a[i]==0) cnt++;
    }
    for(int i=2;i<=n-1;i++){
        if(a[i]==a[i-1]||a[i]==a[i+1]) f1=1;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==1&&f2==1&&i-id>1) break;
        if(a[i]==1){
            f2=1;
            id=i;
        }
        if(i==n) f2=0;
    }
    if(k==0&&f==0){
        cout<<n/2;
        return 0;
    }
    else if(k==0&&f1==0){
        cout<<max(sum/2,cnt);
        return 0;
    }
    else if(k==0&&f2==0){
        cout<<sum/2+cnt;
    }
    else if(k==1){
        cout<<sum;
        return 0;
    }
    else if(k==0){
        cout<<max(sum/2,cnt);
    }
    else{
        cout<<0;
    }
    return 0;
}
