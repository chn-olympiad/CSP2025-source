#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],s[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int cnt=0,l=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]^a[i];
        for(int j=i;j>l;j--){
            if((s[i]^s[j-1])==k){
                cnt++;l=i;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}

