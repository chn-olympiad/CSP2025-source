#include<iostream>
using namespace std;
int n,m,N=998244353,c;
long long a;
string b;
int main(){
    cin>>n>>m>>b;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a==0)c++;
    }
    a=1;
    for(int i=1;i<=n-c;i++){
        a=a*i;
    }
    cout<<a%N;
    return 0;
}
