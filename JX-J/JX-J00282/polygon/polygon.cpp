#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
vector<long long> arr;
long long fang=0,cnts=0;
string decc2bin(long long a,long long mylen){
    long long len=0;
    string s;
    while(a){
        if(a%2==1)++len;
        s=to_string(a%2)+s;
        a/=2;
    }
    if(a%2==1)++len;
    if(len<3)return "NONE";
    for(long long i=0;i<(mylen-s.length());i++)s="0"+s;
    return s;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,datas,lasts;
    string myzu;
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>datas;
        arr.push_back(datas);
    }
    sort(arr.begin(),arr.end());
    for(long long i=0;i<pow(2,n);i++){
        myzu=decc2bin(i,n);
        if(myzu=="NONE")continue;
        cnts=0;
        for(long long j=0;j<n;j++){
            if(myzu[j]=='1'){
                cnts+=arr[j];
                lasts=arr[j];
            }
        }
        if(cnts>(lasts*2))++fang;
    }
    cout<<fang;
    return 0;
}
