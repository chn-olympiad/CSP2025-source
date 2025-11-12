#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    vector<int>stick(n);
    for(int i=0;i<n;i++){
        cin>>stick[i];
    }
    sort(stick.begin(),stick.end());
    vector<long long>sum(n+1,0);
    for(int i=0;i<n;++i){
        sum[i+1]=sum[i]+stick[i];
    }
    cout<<sum[1];
}
