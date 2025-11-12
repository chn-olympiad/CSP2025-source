#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=11e5;
ll k,n,sum,x,cnt;
int a[N];
ll d[N];
bool f[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    d[1]=a[1];
    for(int i=2;i<=n;i++){
        d[i]=d[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((d[j]==k&&j==i)||((d[j]^d[j-i])==k)){
                bool b=1;
                for(int k=j-i+1;k<=j;k++){
                    if(f[k]){
                        b=0;
                        break;
                    }
                }
                if(b){
                   sum++;
                   for(int k=j-i+1;k<=j;k++) f[k]=1;
                    j+=i;
                }
            }
        }
    }
    cout<<sum;
    return 0;
}

