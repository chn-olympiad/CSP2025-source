#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],b[500005],num,l=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j>=l;j--){
            if(b[i]^b[j-1]==k){
                num++;
                l=i+1;
                break;
            }
        }
    }
    cout<<num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}