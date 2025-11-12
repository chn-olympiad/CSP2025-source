#include <iostream>
using namespace std;

int n,k,a[500005],cnt;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(k==0){
        for(int i=1;i<=n;){
            if(a[i]==0){
                cnt++;
                i++;
            }
            else if(a[i]==1 && a[i+1]==1){
                cnt++;
                i+=2;
            }
            else i++;
        }
    }

    else if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
