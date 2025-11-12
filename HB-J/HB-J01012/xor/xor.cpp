#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,k,a[500002],mn=0,c=-1,m=0;
    cin>>n>>k;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==k){
            mn++;
        }
    }for(long long i=0;i<n;i++){
        if(a[i]==k){
            m++,c=-1;
            continue;
        }if(c==-1){
            c=a[i];
            continue;
        }c^=a[i];
        if(c==k){
            m++,c=-1;
            continue;
        }
    }cout<<max(mn,m);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
