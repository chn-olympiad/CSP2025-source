#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon","r",stdin);
    freopen("polygon","w",stdout);
    int n,a[10000],ans=0,q=0,s=0;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n;j++){
            if(a[j]<a[j+1]){
                int b=a[j+1];
                a[j+1]=a[j];
                a[j]=b;
            }
        }
    }
    for(int i=0;i<n;i++){
        ans+=a[i];
        q++;
        if(2*a[1]<ans&&q>=3){
            s++;
        }
    }
    cout<<s;
    return 0;
}
