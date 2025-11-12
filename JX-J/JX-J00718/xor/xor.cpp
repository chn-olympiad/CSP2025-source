#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.ans","w",stdout);
    int n,k,num=0;
    cin>>n>>k;
    int a[100005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(k==0){
        num=n/2;
    }if(k==1){
        for(int i=0;i<n;i++){
            if(a[i]==1){
                num++;
            }
        }
    }
    cout<<num;
    return 0;
}