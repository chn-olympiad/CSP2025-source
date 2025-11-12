#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    for (int p=1;p<=t;p++){
        int n;
        cin >> n;
        long long sum=0;
        long long h1[n],h2[n],h3[n];
        int l=1;
        for (int i=0;i<n;i++) cin >> h1[i] >> h2[i] >> h3[i];
        for (int i=0;i<n;i++){
            sum+=h1[i];
            h3[i]=h2[i]-h1[i];
        }
        sort(h3,h3+n,cmp);
        for (int i=0;i<n/2;i++){
            sum+=h3[i];
        }
        cout << sum << endl;
    }
    return 0;
}


