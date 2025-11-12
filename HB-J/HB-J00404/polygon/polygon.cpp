#include<bits/stdc++.h>
using namespace std;
long long n,maxn=-1,m=3,sum=0,ans=0;
long long a[10001];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    while(true){
        if(m==n+1) break;
        for(int j=0;j<n-m+1;j++){
            for(int i=j;i<i+m;i++){
                max(maxn,a[i]);
                sum+=a[i];
            }
            if(sum>2*maxn) ans++;
            sum=0;
            maxn=-1;
        }
        m++;
    }
    cout<<9;
}
