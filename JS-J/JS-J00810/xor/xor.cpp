#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m,o=0,k=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0) o++;
        if(a[i]==1) k++;
    }
    if(m==0&&o==0){
        if(n%2==1) cout<<1;
        else{
            cout<<0;
        }
    }else{
        if((k-o)&2==0){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    return 0;
}
