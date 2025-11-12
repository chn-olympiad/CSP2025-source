#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int s[n][m],a[n*m];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int t=a[1];
    sort(a+1,a+n*m+1);
    int b[n*m];
    for(int i=n*m;i>=1;i--){
        b[n*m-i+1]=a[i];
    }
    for(int i=1;i<=n*m;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    int k;
    for(int i=1;i<=n*m;i++){
        if(t==b[i]){
            k=i;
            cout<<k<<endl;
            continue;
        }
    }
    int k1=k;
    for(int i=1;i<m;i++){
        if(k<=n){
            continue;
        }
        else if(k>i*n){
            k=k-n;
        }
    }
    for(int i=1;i<=m;i++){
        if(k1<=i*n && i*n-k1<n){
            if(k-n==0){
                cout<<i<<" "<<n<<endl;
                continue;
            }
            cout<<i<<" "<<n-k+i-1<<endl;
            continue;
        }
    }
    return 0;
}
