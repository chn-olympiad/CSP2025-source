#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000005];
int s[1000005];
int cha[1000005];
int ans=0;
int yh(int a,int b){
    int chu=a;
    if(a<b){
        swap(a,b);
    }
    int sum=0;
    for(int i=1;i<(1<<a);i=i<<1){
        if((a&i) !=(b&i)){
            sum+=i;
        }
    }
    return sum;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=yh(s[i-1],a[i]);
    }
    for(int i=1;i<=n;i++){
        if(s[i]==k){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
