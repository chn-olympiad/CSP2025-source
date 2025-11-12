#include<bits/stdc++.h>
using namespace std;
int a[500005];
int l[500005],r[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int s=0;
    for(int i=1;i<=n;i++){
        int x=0;
        for(int j=i;j<=n;j++){
            x=x^a[j];
            if(x==k){
                s++;break;
            }
        }
    }
    cout<<s<<endl;
    return 0;
}