#include<bits/stdc++.h>
using namespace std;
vector<int> v;
vector<pair<int,int> > p;
void f(int sum,int k,int end,int i){
    if(i<1){
        return;
    }
    if(sum^v[i]==k){
        p.push_back({end,i});
    }else{
        f(sum^v[i],k,end,i-1);
    }
}
int main(){
    int n,k,maxn=0,sum=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    for(int i=n;i>=1;i--){
        f(0,k,i,i);
    }
    for(int i=p.size()-1;i>=0;i--){
        if(p[i].second>maxn){
            maxn=p[i].first;
            sum++;
        }
    }
    cout<<sum;
}