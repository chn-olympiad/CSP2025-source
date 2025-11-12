#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,sum=0;
    long long a[900005]={0};
    long long h=0,c=0;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;++i){
        h=i;
        c=1;
        for(int j=i+1;j<n;++j){
            h+=j;
            c++;
           if(c>=3&&j*2<h){
            sum++;
            cout<<i<<" "<<j<<endl;
           }
        }
    }
    cout<<sum;
    return 0;
}
