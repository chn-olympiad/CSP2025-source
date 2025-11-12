#include<iostream>
using namespace std;
long long n,k;
unsigned int num[500005];
long long last;
long long ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("xor6.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>num[i];
        num[i]^=num[i-1];
    }
    for(long long i=1;i<=n;i++){
    	long long c=num[i]^num[last];
        if(c==k){
            ans++;
            last=i;
        }
    }
    cout<<ans; 
    return 0;
}
