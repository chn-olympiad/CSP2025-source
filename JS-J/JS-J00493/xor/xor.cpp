#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans,k,a[N];
bool flag=true,flag1=true;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)flag=false;
        if(a[i]!=1&&a[i]!=0)flag1=false;
    }
    if(flag1==true){
        if(k==0){
            for(int i=1;i<=n;){
                if(i==n&&a[i]==0){
                    ans++;
                    break;
                }
                if(a[i]==a[i+1]){
                    ans++;
                    i++;
                }
                if(a[i]==0)ans++;
                i++;
            }
        }
        else if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1)ans++;
            }
        }
        cout<<ans;
    }
    return 0;
}
