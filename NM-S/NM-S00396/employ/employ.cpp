// Failed
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;bool problems[510] = {0};
vector<int> employees;
void parseProblems(string s){
    int i = 0;
    for(auto x:s){
        problems[i] = bool(int(x)-48);i++;}}

long long calcEmployees(){
    long long ans = 0;
    bool status= true;
    while (status){
        int deads=0;
        vector<int> survivor = employees;
        for(auto x:problems){
            for(int i=0;i<n;i++){
                if(not(x or (survivor[i]>deads))){
                    survivor[i]=-1;deads++;}}}
        if((n-deads)>m){ans++;}
        status = next_permutation(employees.begin(),employees.end());
    }return ans%998244353;
}
int main(){
    freopen("./employ.in","r+",stdin);
    freopen("./employ.out","w+",stdout);
    string p;cin>>n>>m;
    cin>>p;
    parseProblems(p);
    int tmp;for(int i=n;i;i--){
        cin>>tmp;employees.push_back(tmp);
    }sort(employees.begin(),employees.end());
    
    cout<<calcEmployees()<<endl;
    // // debug //
    // for(int i=0;i<n;i++){
    //     cout<<(problems[i]?'y':'n');
    // }cout<<endl;
    // for(auto x:employees){
    //     cout<<x<<' ';}cout<<endl;
    
    fclose(stdin);
    fclose(stdout);return 0;
}
