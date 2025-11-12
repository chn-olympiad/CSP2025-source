#include<bits/stdc++.h>
using namespace std;
const int inf=5e5+10;
int n,k,a[inf],num,lt,cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int z=1;z<=i;z++){
            num=0;
            if(i-z+1<=lt){
                break;
            }
            for(int j=i-z+1;j<=i;j++){
                num=num xor a[j];
            }
            if(num==k){
                cnt++;
                lt=i;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}
