#include<bits/stdc++.h>
using namespace std;

int n,p[20],maxn,sum;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        maxn=max(maxn,p[i]);
        sum+=p[i];
    }
    if(sum>2*maxn){
        cout<<1;
    }
    else{
        cout<<0;
    }

    return 0;
}
