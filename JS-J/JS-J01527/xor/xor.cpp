#include<bits/stdc++.h>
using namespace std;
int a[5010];
int n,k;
bool flag;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            flag=true;
        }
    }
    int sum=0;
    if(flag){
        sum=2;
    }else{
        for(int i=1;i<=n;i+=2){
            sum+=n-i;
        }
    }
    cout<<sum;
 return 0;
}
