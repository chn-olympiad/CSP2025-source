#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,s=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=3;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            int max1=0,lei=0;
            for(int k=j;k<=j+i;k++){
                if(a[k]>=max1){
                    max1=a[k];
                }
                lei=lei+a[k];
            }
            if(lei>max1*2){
                s++;
            }
        }
    }
    cout<<s;
    return 0;
}
