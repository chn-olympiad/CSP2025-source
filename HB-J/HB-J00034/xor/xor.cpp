#include<bits/stdc++.h>
using namespace std;
int cmp(int a){
    int b,c;
    while(a / 2 > 0){
        if(a % 2 == 0) b++;
        if(a % 2 != 0) c++;
    }
    cout<<b<<" "<<a;
}
int n,m;
const int N = 10010;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cout<<cmp(a[i]);
    }
    return 0;
}
