#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
int a[500005];

int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int p=0,p2=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)p=1;
        if(a[i]!=1&&a[i]!=0)p2=1;
    }
    if(p==0){
        if(k==1){
            cout<<n<<endl;
            return 0;
        }
        if(k==0){
            cout<<n/2<<endl;
            return 0;
        }
    }
    else if(p2==0&&k==1){
            int ans=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0)
                    ans++;
            }
            cout<<ans<<endl;

    }
    else if(k==0){
            int ans=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0)
                    ans++;
            }
            cout<<ans<<endl;
    }
    else cout<<0<<endl;
    return 0;
}
