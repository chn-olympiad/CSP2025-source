#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500001],s[500001],l[500001],r[500001],an=1,m;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==0){
        cout<<0;
        return 0;
    }
    for(int i=1;i<n;i++){
        m=0;
        for(int j=i+1;j<=n;j++){
            m=m&!a[j];
            if(m==k){
                l[an]=i;
                r[an]=j;
                an++;
                break;
            }
        }
    }
    for(int i=n;i>1;i--){
        m=0;
        for(int j=i-1;j>=1;j--){
            m=m&!a[j];
            if(m==k){
                l[an]=i;
                r[an]=j;
                an++;
                break;
            }
        }
    }
    cout<<an+1;
    return 0;
}
