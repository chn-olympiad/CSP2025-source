#include<bits/stdc++.h>
using namespace std;

long long n,k,a[(int)5e5+5];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    int ans=0;
    int i=1;

    while(i<=n){
        for(int j=i;j<=n;j++){
            int s=a[i];
            for(int w=i+1;w<=j;w++){
            s=s|a[w];
            }
            if(s==k){
                ans++;
                i=j;
                break;
            }
        }
        i++;
    }

    cout<<ans;

    return 0;

}
