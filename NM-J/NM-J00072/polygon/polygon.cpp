#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int s,x=0,max_,j=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            s=i;
            x=0;
            max_=0;
            for(int l=0;l<=j+1;l++){
                x+=a[s];
                if(a[s]>max_){
                    max_=a[s];
                }
                s++;
            }
            if(max_*2<x){
                j++;
            }
        }
    }
    cout<<j%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
