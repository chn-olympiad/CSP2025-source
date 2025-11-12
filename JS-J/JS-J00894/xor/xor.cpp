#include <bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int a[N],p[N];
int main(){

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    for(int i =1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int j=i;
        long long sum=a[i];
        while(j<=n){

            if(sum==k){
                p[i]=j;

                break;
            }
            j++;
            sum=sum^a[j];
        }
    }
    int cnt=0;
    for(int i =1;i<=n;i++){
        if(p[i]!=0){
            cnt++;
            i=p[i];
        }
    }
    cout<<cnt;
    return 0;
}
