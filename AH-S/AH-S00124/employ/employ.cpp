#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    int a[n];
    string b;
    cin>>n>>m;
    cin>>b;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(a[i]<a[i-1]){
                int s;
                s=a[i];
                a[i]=a[i-1];
                a[i-1]=s;
            }
        }
    }
    return 0;
}
