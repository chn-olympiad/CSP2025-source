#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    ll a[n+1]={};
    ll s[n+1]={0};
    for(ll rp=1;rp<=n;rp++){cin>>a[rp],s[rp]=(s[rp-1]^a[rp]);}
    unsigned long long cnt=0;
    for(ll i=1;i<=n;i++){//i:l
        for(ll j=i;j<=n;j++){//j:r
            //cout<<((s[j]^s[i-1])==55)<<endl;
            //cout<<i<<" "<<j<<":"<<(s[j]^s[i-1])<<" ";
            if((s[j]^s[i-1])==k){
                cnt++,i=j;
                //cout<<i<<endl;
                break;
            }
            //cout<<endl;
        }
    }
    //I have a great idea which can optimize it to O(nlogn),but the file has no free space
    //Actually because I can't face that the optimization by me gave the WrongAnswers...
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
