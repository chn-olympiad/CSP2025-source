#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==0){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0) cnt++;
        }
        cout<<cnt<<endl;
    }
    if(k==1){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
