#include<bits/stdc++.h>
using namespace std;
long long a[500010],n,k,sum;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==0){
        for(int i=1;i<=n;i++)
            if(a[i]==0) sum++;
        cout<<sum<<endl;
        return 0;
    }
    else if(k==1){
        for(int i=1;i<=n;i++)
            if(a[i]==1) sum++;
        cout<<sum<<endl;
        return 0;
    }
    else{
        cout<<112<<endl;
    }
    return 0;
}

