#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,num=0;
    cin>>n;
    int a[n]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int t=j+1;t<n;t++){
                if(a[i]+a[j]+a[t]>2*max(a[i],max(a[j],a[t]))){
                    num++;
                }
            }
        }
    }
    cout<<num;

    return 0;
}
