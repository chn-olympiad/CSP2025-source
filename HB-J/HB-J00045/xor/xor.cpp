#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],num,num2;
string s;
int main(){
    freopen("xor","r",stdin);
    freopen("xor","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0)
            num2++;
        if(a[i]==1)
            num++;
    }
    if(k==0){
        cout<<num2;
    }else if(k==1){
        cout<<num;
    }else
        cout<<abs(n-k);
    return 0;
}
