#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int s[N];
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    cin>>a[0];
    s[0]=a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        s[i]=a[i]^s[i-1];
    }
    cout<<n;
    return 0;

}
