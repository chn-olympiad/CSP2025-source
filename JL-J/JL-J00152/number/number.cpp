#include<bits/stdc++.h>
using namespace std;

string a;
int n;
int sum[12];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    n = a.size();
    a = " " +a;
    for(int i = 1;i <= n;i++){
        if('0' <= a[i] && a[i]<= '9') sum[a[i] - '0']++;
    }
    for(int i = 9;i >= 0;i--){
        while(sum[i]--) cout<<i;
    }
}
