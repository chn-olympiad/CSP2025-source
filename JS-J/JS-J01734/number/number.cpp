#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream fin("number.in");
    ofstream fout("number.out");

    string s;
    fin>>s;
    vector<int>num(10,0);
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9')num[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<num[i];j++)fout<<i;
    }

    return 0;
}