#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],num1,mx,b[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)num1++;
    }
    cout<<num1<<endl;
    return 0;
}
