#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int f[500010];
int s;
int x;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=f[i-1]|a[i];
    }
    for(int i=2;i<=n;i++){
        for(int j=i;j<=n;j++){
            x=f[j]|f[i];
            if(x==k){
                s+=1;
                i=j+1;
                break;
            }
        }
    }
    cout<<s<<endl;
    return 0;
}
