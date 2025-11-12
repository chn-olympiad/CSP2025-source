#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int a[N];
int n;
int sum = 0;
int maxx = 0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            maxx = max(a[i],a[j]);
            if(a[j] > a[i]){
                if(a[i]+a[i+1] > a[j]){
                    sum++;
                }
                if(a[j]<a[i]){
                    if(a[j]+a[j+1] > a[i]){
                        sum++;
                    }
                }
                if(a[j] == a[i]){
                    if(a[j] + a[j+1] > a[i] || a[i]+a[i+1] > a[j]){
                        sum++;
                    }
                }
            }
        }
    }
    cout<<sum % 998244353;
    return 0;
}
