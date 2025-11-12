#include<bits/stdc++.h>
using namespace std;

long long a[500005];

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    long long n, k;
    int sum=0, ans=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int x=i;x<n;x++){
            for(int y=x;y<n;y++){
                sum=a[x];
                for(int j=x;j<=y;j++){
                    sum=(sum|a[j]);
                }
                if(sum==k){
                    ans++;
                    i=y+1;
                    x=y+1;
                    y=x;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
