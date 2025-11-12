#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],s;
bool us[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            us[i]=true;
            s++;
        }
    }
    for(int i=1;i<=n;i++){
        if(!us[i]){
            for(int j=i+1;j<=n;j++){
                if(us[j]){
                    break;
                }
                a[i]=a[i]^a[j];
                if(a[i]==k){
                    i=j;
                    s++;
                    break;
                }
            }
        }
    }
    cout<<s;
    return 0;
}
