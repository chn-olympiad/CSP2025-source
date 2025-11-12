#include<bits/stdc++.h>
using namespace std;
int n,m,k=0,ans=0;
char a[1001];
int c[10001];
int main(){
    cin>>n>>m;
    for(int i=1;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        cin>>c[i];
    }
    for(int j=1;j<=n;j++){
        if(a[j]=="0"){
            k++;
        }
        if(k>=c[j]) n-=1;
    }
    if(n>=m) cout<<n;
}
