#include<bits/stdc++.h>
using namespace std;
long long n,k,cnt;
long long a[1000000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin.tie(nullptr);cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<+n;i++){
        if(a[i]==a[n]) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
