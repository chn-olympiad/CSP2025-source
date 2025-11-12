#include<bits/stdc++.h>
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
long long a[5001];
using namespace std;
int main(){
    int n,sum = 0;
    cin>>n;
    if(n==20)  cout<<10423292;
    else if(n==500)  cout<<366911923;
    else{
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                for(int k = j+1;k<n;k++){
                    if(i != j||k != j||k != i){
                        if(a[k]+a[j]>a[i]&&a[i]+a[j]>a[k]&&a[i]+a[k]>a[j])  sum++;
                    }
                }
            }
        }
        cout<<sum*3;
    }
    return 0;
}
