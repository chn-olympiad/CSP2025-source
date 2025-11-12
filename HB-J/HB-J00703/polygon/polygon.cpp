#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5006];
    cin >>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(n==3){
        if(a[0]+a[1]>a[2]){
            cout<<1;
            return 0;
        }
        cout<<0;
        return 0;
    }
    int cnt=0,sum=0,k=2,bs=2,sum1=0;
    for(int i=2;i<n;i++){
        k=i-1;
        while(k>=0){
            sum+=a[k];
            k--;
        }
        if(sum<=a[i]){
            continue;
        }
        else{
            for(int j=0;j<i;j++){
                if(sum-a[j]<=a[i]){
                    continue;
                }
                else{
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
