#include<bits/stdc++.h>
using namespace std;

int n,k,a[500001],ans=0;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==k) {
            a[i]=-1;ans++;
        }else{
        }
    }
    for(int i=1;i<=n;i++){
        int sum=a[i];
        for(int j=i+1;j<=n && a[i]!=-1;j++){
            sum^=a[j];
            if(sum==k){
                i=j;
                ans++;
                break;
            }
        }
    }

    cout<<ans;
    fclose(stdin);
    fclose(stdout);

    return 0;
}
