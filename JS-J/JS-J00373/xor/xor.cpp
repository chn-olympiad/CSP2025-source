#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500001],num=0,maxn=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int g=0;g<n;g++){
    num=0;
    for(int i=g;i<n;i++){
        int xx=a[i];
        for(int j=i+1;j<=n;j++){
            if(xx==k){
                num++;
                i=j-1;
                break;
            }
            xx=(xx^a[j]);
        }
    }
    maxn=max(maxn,num);
    }
    cout<<maxn;
    return 0;
}
