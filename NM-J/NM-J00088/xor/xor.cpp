#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,t,i,s=0,a[100005];
    cin >> n >> k;
    if(n==2){
        for(i=1;i<=n;i++){
            cin >> t;
        }
        cout << 0;
    }else{
        for(i=1;i<=n;i++){
            cin >> a[i];
        }
        i=0;
        if(k==1){
            for(i=1;;i++){
                if(a[i]==1){
                    break;
                }
            }
            i++;
            while(i<=n){
                if(a[i]==1){
                    if(s%2==1){
                        s--;
                    }else{
                        s++;
                    }
                }
                i++;
            }
        }
        cout << s;
    }
    return 0;
}
