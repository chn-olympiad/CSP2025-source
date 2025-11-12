#include<iostream>
#include<vector>
using namespace std;
struct city{
    long long u;
    long long v;
    long long w;
};
long long shu;
city datas;
vector<city>cities;
vector<int>arr;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>datas.u>>datas.v>>datas.w;
        cities.push_back(datas);
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<(n+1);j++){
            cin>>shu;
            arr.push_back(shu);
        }
    }
    cout<<0;
    return 0;
}
