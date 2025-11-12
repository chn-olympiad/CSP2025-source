#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>num(10005,10005);
int duobianxing(int p,int t,int sum){
    // cout<<p<<" "<<t<<endl;
    int cnt=((t>num[p])&&(sum>2));
    // cout<<cnt<<endl;
    for(int i=p+1;i<=n;i++){
        cnt+=duobianxing(i,t+num[i],sum+1);
    }
    // cout<<p<<" "<<t<<" "<<cnt<<" "<<sum<<endl;
    return cnt;
}
int main(){
    ifstream fin("polygon.in");
    ofstream fout("polygon.out");

    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>num[i];
    }
    // for(int i=1;i<=n;i++){
    //     cout<<num[i];
    // }
    num[0]=0;
    sort(num.begin(),num.end());
    // for(int i=1;i<=n;i++){
    //     cout<<num[i];
    // }
    fout<<duobianxing(0,0,0)%998244353;

    return 0;
}