#include<iostream>
using namespace std;

long long a[500010];
long long n,k;
long long ans;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        a[i]=t;
        if(k==0 && (a[i]==0 || a[i]==a[i-1])){
            ans++;
        }
        else if(k==1 && a[i]==1){
            ans++;
        }
    }
    cout<<ans;



    return 0;
}

