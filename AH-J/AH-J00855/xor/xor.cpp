#include<bits/stdc++.h>
using namespace std;
int a[10010];
int ans[100010];
int n,k;
int num;
int cnt;
int an;
int sum[10010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1){
            num++;
        }
    }
    if(k==1){
        cout<<num;
    }else{
        cout<<num/2;
    }
    return 0;
}
