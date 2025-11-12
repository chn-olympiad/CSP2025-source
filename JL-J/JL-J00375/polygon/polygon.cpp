#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n;
    cin>>n;
    long long a[n+10]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long o=0,d=0,sum=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int l=j+1;l<n;l++){
                o=a[i]+a[j]+a[l];
                d=max(d,max(max(a[i],a[j]),max(a[j],a[l])));
                if(d*2<o)sum++;
//                cout<<a[i]<<" "<<a[j]<<" "<<a[l]<<" "<<endl;
            }
        }
    }
    cout<<sum;
    return 0;
}
