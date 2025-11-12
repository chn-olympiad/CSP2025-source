#include<bits/stdc++.h>
using namespace std;

string s;
vector<int> a;
int num[9];

void st(vector<int> x){
    for(int i=0;i<x.size();i++){
        for(int j=0;j<=9;j++){
            if(x[i]==j) num[j]++;
        }
    }
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a.push_back(s[i]-'0');
        }
    }
    st(a);
    for(int j=9;j>=0;j--){
        for(int i=0;i<num[j];i++){
            cout<<j;

        }
    }

    return 0;
}
