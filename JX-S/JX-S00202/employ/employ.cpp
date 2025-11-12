#include<iostream>
#include<string>
#include<vector>
using namespace std;
long long n,m,datas,num=1;
long long cntss=1;
string s;
vector<long long> arr;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    getline(cin,s);
    for(long long i=0;i<n;i++){
        cin>>datas;
        arr.push_back(datas);
    }
    for(int i=0;i<n;i++){
        cntss=((cntss%998244353)*num)%998244353;
        ++num;
    }
    cout<<cntss;
    return 0;
}
