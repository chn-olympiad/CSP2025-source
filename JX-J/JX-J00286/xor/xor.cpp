#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define LL long long
const int N=5e5+5;
int a[N],s[N];
int n,k;
int main(){
    IOS;
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(a[i]==k){
                ans++;
                break;
            }else if(a[j]==k){
                ans++;
                i=j;
                break;
            }else if((s[j]^s[i-1])==k){
                ans++;
                i=j;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
