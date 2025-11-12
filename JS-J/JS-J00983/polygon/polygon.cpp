#include<bits/stdc++.h>
using namespace std;
int sum=0;
vector<int> v;
void f(int n,int s,int c,int i){
    if(i>n){
        return;
    }
    if(c+1>=3&&s+v[i]>2*v[i]){
        sum++;
        sum%=998244353;
    }
    f(n,s,c,i+1);
    f(n,s+v[i],c+1,i+1);
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    f(n,0,0,1);
    cout<<sum;
}