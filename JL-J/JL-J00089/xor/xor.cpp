#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500050];
long long t[500050];
map<long long,long long>mp;
int cmp(int x,int y){
    return x>y;
};
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    long long x=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1){
            x++;
        }
        if(x==n-1&&k==0){
            cout<<n/2;
            return 0;
        }
    }
    if(k==1||k==0){
        long long sl=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(abs(a[i]-a[j])==k&&i>j){
                    sl++;
                    j=i+1;
                }
            }
        }
        cout<<sl;
        return 0;
    }
    return 0;
}
