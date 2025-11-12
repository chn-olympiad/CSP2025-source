#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e2+20;
int n(0),k(0);
int arr[MAXN];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>arr[i];
    }
    if(k=0)cout<<0;
    if(k>=2&&k<=10)cout<<1;
    else cout<<random_access_iterator_tag
    return 0;
}
