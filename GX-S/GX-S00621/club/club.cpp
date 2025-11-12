#include<bits/stdc++.h>
using namespace std;
int a1[100000];
int a2[100000];
int a3[100000];
int b1[100000];
int b2[100000];
int b3[100000];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.ans","w",stdout);
    long long t;
    cin>>t;
    long long n;
    for(long long i = 0 ; i < t; i++){
        cin>>n;
        for(int j = 0;j<n;j++){
            cin>>a1[j]>>a2[j]>>a3[j];
        }
        sort(a1,a1+n);
        sort(a2,a2+n);
        sort(a3,a3+n);
        long long aaa = n;
        for(int j = 0;j<n;j++){
            b2[j] = a2[aaa];
            b1[j] = a1[aaa];
            b3[j] = a3[aaa];
            aaa--;
        }
        long long v = 0;
        for(int i = 0;i<n/3;i++){
            v+=b1[i]+=b2[i]+=b3[i];
        }
        cout<<v;
    }
    /*
    the last cristmas
    I gave u my heart
    */
    return 0;
}
