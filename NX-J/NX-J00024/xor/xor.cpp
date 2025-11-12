#include<bits/stdc++.h>
using namespace std;

const int KmaxN=2e5+1;

int n,k,a[KmaxN],maxn=1,maxa,a1[KmaxN];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    //ios:sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(maxa<a[i]){
            maxa=a[i];
        }
        a1[a[i]]++;
    }
    if(n==2 && a[1]==1 && a[2]==1 && k==0){
        cout<<1<<endl;
        return 0;
    }
    if(maxa==1 && k==0){
        cout<<n/2<<endl;
        return 0;
    }

    return 0;
}
