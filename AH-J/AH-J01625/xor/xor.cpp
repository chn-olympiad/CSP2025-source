#include<iostream>
using namespace std;
int n,k,a[500005],cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=1,r=1,sum=a[1];
    while(l<=n&&r<=n){
        while(sum!=k){
            r++;
            sum^=a[r];
        }
        cnt++;
        r++;
        l=r;
        sum=a[l];
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
