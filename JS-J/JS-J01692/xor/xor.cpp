#include <iostream>
using namespace std;
int a[100005];
int dp[100005];
int main(){
    int n,k;
    cin>>n>>k;
    int z = 0;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    int j = 1,i = 1,qr = 0;
    for(int l = j;l <= i;l++){
        qr++;
        int mo = a[l];
        if(mo == k){
            cout<<j<<l;
            j = l+1;
            i = l+1;
            z++;

        }
        else{
            mo = mo ^ a[l];
            i++;
        }
        if(i == n) j++;
    }
    cout<<z<<endl<<qr;
}
