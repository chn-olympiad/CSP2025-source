#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n,k;
long long a[N];
long long s[N];
long long sum ;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        s[i] = a[i] ^ s[i-1];
        //if(ans[i] ^ ans[i-1] == k) cout<<i<<" ";
    }
    long long l = 1;
    long long lastl = 1;
    int flag = 0;
    //cout<<
    for(long long r=1;r<=n;r++){
        lastl = l;
        flag = 0;
        while(l <= r){

            if(abs(s[r] - s[l-1]) == k){
                //cout<<l<<" "<<r<<endl;
                sum++;
                l = r;
                flag = 1;
                break;
            }else{
                l++;
            }
        }
        if(flag == 0){
            l = lastl;
        }
    }
    printf("%d",sum);
    return 0;
}
