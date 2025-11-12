#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,sum = 0;
    cin>>n>>m;
    int a[10001];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i =1;i<=n;i++){
        for(int j = 1;j<=n;i++){
            if(a[i]|a[i+j] == m){
                sum ++;
            }
        }
    }
    cout<<sum;
    return 0;
}
