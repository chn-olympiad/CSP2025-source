#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5010];
int n;
int maxn=0;
int cnt=0;
int ans=0;
int s;
const int N1=998,N2=244,N3=353;
int fun(int i){
    if(maxn<a[i])maxn=a[i];
    s+=a[i];
    for(int j=i+1;j<=n;j++){
        cnt+=fun(j);
    }
    if(maxn*2>=s)return 0;
    else return 1;
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        s=0;
        cnt=0;
        ans+=fun(i);
    }
    cout<<ans;
    return 0;
}
