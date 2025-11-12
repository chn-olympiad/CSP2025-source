#include<bits/stdc++.h>
using namespace std;
long long n,m,f,sum=-1;
vector<int> v;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        int k;
        cin>>k;
        v.push_back(k);
    }
    f=v[0];
    sort(v.begin(),v.end(),cmp);
    int p=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==f) p=i;
    }
    for(int i=0;i<m;i+=2){
        sum+=n;
        if(sum>=p){
            cout<<i+1<<' '<<p-(sum-n)<<endl;
            break;
        }
        sum+=n;
        if(sum>=p){
            cout<<i+2<<' '<<n-(p-(sum-n))+1<<endl;
            break;
        }
    }
    return 0;
}
