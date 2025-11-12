#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string s;
long long n;
vector<long long> vec;
bool cmp(long long q,long long p){
    return q>p;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    for(long long i=0; i<n; i++){
        if(s[i]>='0'&&s[i]<='9'){
            vec.push_back(s[i]-'0');
        }
    }
    sort(vec.begin(),vec.end(),cmp);
    for(long long t : vec){
        cout<<t;
    }
    return 0;
}
