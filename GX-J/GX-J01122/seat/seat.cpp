#include<bits/stdc++.h>
using namespace std;
int cnt1[120];
int cnt[120];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long a,b;
    cin>>a>>b;
    long long k;
    long long n = a*b;
    for(long long i = 0;i<n;i++){
        cin>>cnt1[i];
    }
    k = cnt1[0];
    sort(cnt1,cnt1+n);
    long long v = 0;
    for(int i = n-1;i>=0;i--){
        cnt[v] = cnt1[i];
        v++;
    }
    long long mo = 0;
    for(int i = 0;i<n;i++){
        if(cnt[i] == k){
            mo = i+1;
        }
    }
    long long c1 = mo%b+1;
    long long c2 = mo%b;
    if(c1%2 == 0){

        cout<<c1<<" "<<c2;
    }
    else{
        if(c2 == 1){
            cout<<c1<<" "<<b-c2;
            return 0;
        }

        cout<<c1<<" "<<b-c2+1;
    }


    return 0;
}
