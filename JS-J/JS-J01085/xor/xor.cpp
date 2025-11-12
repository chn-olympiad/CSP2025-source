#include<bits/stdc++.h>
using namespace std;
long long a[1000001],b[1000001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,k;
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long ans=0;
    if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1)ans++;
        }
        cout<<ans<<endl;
        return 0;
    }
    if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==0)ans++;
            else if(a[i]==a[i+1]){
                ans++;
                i++;
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==k)ans++;
        else{
            if(a[i]!=0){
                long long total=0;
                for(int j=i;j<=n;j++){
                    total+=a[j];
                    if(total%k==0){
                     //   cout<<total<<endl;
                        ans++;
                        break;
                    }
                }
            }
        }

    }
    cout<<ans<<endl;
    return 0;

}
