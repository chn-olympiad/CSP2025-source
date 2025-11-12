#include <bits/stdc++.h>
using namespace std;
int m[110],x,ma=0;
long long sum;
int jie(int n,int m){
    if(m==1){
        return n;
    }
    for(int i=2;i<=m;i++){
        n*=10;
    }
    return n;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int l=a.length();
    for(int i=0;i<l;i++){
        if(a[i]-'0'>=0&&a[i]-'0'<=10){
            x=a[i]-'0';
            m[x]++;
            ma++;
            }
    }
    for(int i=9;i>=0;i--){
        while(m[i]>0){

            cout<<i;
            m[i]--;

        }
    }

    return 0;
}
