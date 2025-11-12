#include<bits/stdc++.h>
using namespace std;

bool sortRule(char a,char b){
    return a>b;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string input;
    cin>>input;

    vector<char> numbers;
    for(int i=0;i<input.size();++i){
        if(input[i]>='0'&&input[i]<='9')
            numbers.push_back(input[i]);
    }

    sort(numbers.begin(),numbers.end(),sortRule);

    for(int i=0;i<numbers.size();++i)
        cout<<numbers[i];

    return 0;
}
