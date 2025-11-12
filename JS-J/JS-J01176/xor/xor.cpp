#include<bits/stdc++.h>
using namespace std;
long long n,c,k;
bool f1=true,f2=false;
long long a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    sizeof(a,-1,sizeof(a));
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=0&&a[i]!=1)f1=false;
        if(a[i]==0)f2=true;
    }
    if(f1&&f2==false){
        cout<<n/2;
    }
    if(f1&&f2){
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0)c++;
                if(a[i]==1&&a[i+1]==1){
                    c++;
                    i++;
                }
            }
        }
        if (k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1)c++;
            }
        }
        cout<<c;
    }
    return 0;
}
