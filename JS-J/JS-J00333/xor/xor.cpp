#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],b[N],c[N];
long long dp(int s,int n){
    long long ans=0;
    for(int i=s;i<=n;i++){
        if(b[i]){
            ans=max(ans,dp(c[i]+1,n)+1);
        }
    }
    return ans;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long cnt=0;
    long long cnt1=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
			if(i==j&&a[i]==k){
				b[i]=1;
				c[i]=j;
				break;
			}
            cnt=0;
            for(int u=i;u<=j;u++){
                cnt=int(cnt^a[u]);
            }
            if(cnt==k){
                cnt1++;
                b[i]=1;
                c[i]=j;
                break;
            }
        }
    }
    cout<<dp(1,n);
    return 0;
}

