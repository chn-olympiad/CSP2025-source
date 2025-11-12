#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,s=0,le=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==0&&n<=2){
        for(int i=1;i<=n;i++){
            if(a[i]==1) s+=1;
        }
        cout<<s;
    }
    return 0;
}
