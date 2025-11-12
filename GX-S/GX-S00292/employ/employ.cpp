#include<bits/stdc++.h>
using namespace std;

int jc(int n){
    if(n == 1) return 1;
    else return (n*jc(n-1))%99824435;
}

int main(){
    int n,
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin>>n;
    cout<<jc(n);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
