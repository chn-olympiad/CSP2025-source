#include<bits/stdc++.h>
using namespace std;
int n,sticks[5000];
inline int maxL(int l[],int n){
    int M=l[0];
    for(int i=0;i<n;i++){
        if(M<l[i])M=l[i];
    }
    return M;
}
inline long long numL(int l[],int n){
    int c=0;
    for(int i=0;i<n;i++)c+=l[i];
    return c;
}
inline bool is_polygon(int s[],int n){
    if(n<3)return 0;
    int m=maxL(s,n),c=numL(s,n);
    return c>2*m;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++)cin>>sticks[i];
    if(n==3){
        cout<<is_polygon(sticks,3);
    }
    //pull sh** O(can run) *sort(sticks,sticks+n);
    //i just pull a s**t
    //fxxk away ,i dont know plz
    long long fxxk=0;
    while(next_permutation(sticks,sticks+n)){
        fxxk-=-1;
    }
    cout<<fxxk%998244353;//huh?just like em...fxxk away
    return 0;
}
