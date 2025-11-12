#include<bits/stdc++.h>
using namespace std;
int n,k,sum,L,a[500005];
bool f=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);	
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i],f&=(a[i]<=1);
    if(f){
        if(k==0)for(int i=1;i<=n;++i)sum+=(a[i]==0);
        if(k==1) for(int i=1;i<=n;++i)sum+=a[i];
        cout<<sum; 
        return 0;
    }
    for(int i=1;i<=n;++i){
        int ans=0;
        for(int j=i;j>L;--j){
            ans^=a[j];
            if(ans==k){
                L=i;
                sum++;
                break;
            }
        }
    }
    cout<<sum;
    return 0;
}
