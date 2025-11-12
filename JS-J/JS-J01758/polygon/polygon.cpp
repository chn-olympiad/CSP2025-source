#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int sz=200050;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[sz];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        cout<<1;
        return 0;
    }
    else if(n<3){
        cout<<0;
        return 0;
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(i+j>k&&i+k>j&&k+j>i){
                    sum++;
                }
            }
        }
    }
    cout<<sum;
    cout<<endl;
    return 0;
}
//By Mr.Han
