#include <iostream>
using namespace std;
int fw[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[500005],m=0,cnt=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        fw[i]=(fw[i-1]&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=1;k<=n-j;k++){
                if(fw[j+k]^fw[j]==k){
                    cnt++;
                    j+=k;
                    break;
                }
            }
        }
        if(cnt>m)m=cnt;
        cnt=0;
    }
    cout<<m;
}
