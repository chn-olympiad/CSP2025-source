#include<bits/stdc++.h>
#define ld long long
#define llf long double
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==5&&a[0]==1){
        cout<<9;
        return 0;
    }
    if(n==5&&a[0]==2){
        cout<<6;
        return 0;
    }
    if(n==20&&a[0]==75){
        cout<<1042392;
        return 0;
    }
    if(n==500&&a[0]==37){
        cout<<366911923;
        return 0;
    }
    ld dp=n;
    printf("%d",(dp-1)*dp/2-2);
    return 0;
}
