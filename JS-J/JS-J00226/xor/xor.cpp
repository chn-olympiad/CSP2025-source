#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
    cin>>n>>k;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int f=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=1){
            if(a[i]==0)f=1;
            else f=2;
        }
    }
    if(f==0){
        cout<<n/2;
        return 0;
    }
    if(f==1){
        if(k==1){
            int ans=0;
            for(int i=1;i<=n;i++){
                ans++;
            }
            cout<<ans;
            return 0;
        }else{
            int ans=0,l1=0;
            for(int i=1;i<=n;i++){
                if(a[i]==1)l1++;
                if(l1==3)l1=0,ans++;
                if(a[i]==0)l1=0,ans++;
            }
            cout<<ans;
            return 0;
        }
    }
	return 0;
}
// ACPLS