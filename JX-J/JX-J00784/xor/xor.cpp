#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+7;
string s;
int a[N],n,k,cnta,cntb;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1){
            cnta++;//select A
            cntb++;//B
        }
        if(a[i]==0){
            cntb++;//B
        }
    }
    //do A
    if(cnta==n&&k==0){
        cout<<n-1;
        return 0;
    }
    //do B
    int cnt;
    if(cntb==n){
        if(k==0){
            for(int i=1;i<n;i++){
                if(a[i]==a[i+1]){
                    cnt++;
                }
            }
            cout<<cnt;
            return 0;
        }else if(k==1){
            for(int i=1;i<n;i++){
                if(a[i]!=a[i+1]){
                    cnt++;
                }
            }
            cout<<cnt;
            return 0;
        }
    }
    cout<<n/2;
    return 0;
}

