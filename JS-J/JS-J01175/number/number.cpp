#include<bits/stdc++.h>
using namepace std;
int main(){
    ifstream fin("number.in");
    ofstream fout("number.out");
    string a;
    vector<int> b;
    fin>>a;
    for(int i=0;i<a.size;i++){
            b.push_back(a[i]);
    }
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    for(int i:b){
        fout<<i;
    }
    fin.close();
    fout.close();
    return 0;
}

