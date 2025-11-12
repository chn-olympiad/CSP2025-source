#include<bits/stdc++.h>
using namespace std;
string a;
priority_queue<int,vector<int>,greater<int> > n;
int m[100001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,a);
    long long len=a.length();
    for(long long i=0;i<len;i++){
        if(a[i]>=48&&a[i]<=57){
            n.push(a[i]-48);
        }
    }
    long long k=0;
    while(!n.empty()){
        m[k]=n.top();
        k++;
        n.pop();
    }
    for(long long i=k-1;i>=0;i--){
        cout<<m[i];
    }
    return 0;
}
