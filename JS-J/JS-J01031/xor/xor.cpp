#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int main(){
    ifstream fin("xor.in",ios::in);
    ofstream fout("xor.out",ios::out);

    int n,k;fin>>n>>k;
    for(int i=0;i<n;i++){
        int t;fin>>t;
        v.push_back(t);
    }

    int sum=-1,count=0;
    for(int i=0;i<v.size();i++){
        if(sum==-1) sum = v[i];
        else sum = sum^v[i];
        if(sum==k){
            count++;
            sum = -1;
        }
    }
    fout<<count;
    return 0;
}
