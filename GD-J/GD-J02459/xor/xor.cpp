#include <bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005]={0};
long long sm[500005]={0};
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    int f=1;
    for(int i=1;i <= n;i++){
        cin >> a[i];
        if(i==1){
            sm[1]=a[1];
        }
        else{
            sm[i]=a[i]^sm[i-1];
            //cout << a[i] << ' ' << sm[i-1] << ' ' << sm[i] << endl;
        }
        if(a[i]==0&&f<2){
            f=2;
        }
        if(a[i]>1&&f<3){
            f=3;
        }
    }
    long long ans=0;
    if(f==1){
        cout << n/2;
        return 0;
    }
    else if(f==2){
        if(k==1){
            for(int i=1;i <= n;i++){
                if(a[i]==1){
                    ans++;
                }
            }
        }
        else{
            for(int i=1;i <= n;i++){
                if(a[i]==0){
                    ans++;
                }
                else if(a[i]==a[i-1]&&a[i]==1){
                    ans++;
                    a[i]=0;
                }
            }
        }
        cout << ans;
        return 0;
    }
    else{
       // for(int i=1;i <= n;i++){
         //   cout << sm[i] << ' ';
        //}
        //cout << endl;
        long long mn=0;
        for(int i=1;i <= n;i++){
            for(int j=mn+1;j <= i;j++){
                if((sm[i]^sm[j-1])==k){
                    mn=i;
                    ans++;
                   // cout << j << ' ' << i << ' ' << sm[j-1] << ' ' << sm[i] << ' ' << (sm[i]^sm[j-1]) << ' ' << k << endl;
                    break;
                }
            }
        }
        cout << ans;
        return 0;
    }
    return 0;
}
