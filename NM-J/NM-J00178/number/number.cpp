#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin>>s;
    vector<int> data;
    for(int i = 0;i<s.size();i++){
        if(s[i] <= '9' && s[i] >= '0'){
            data.push_back(s[i] - '0');
        }

    }
    sort(data.begin(),data.end(),greater<int>());
    for(long long i = 0;i<data.size();i++){
        cout<<data[i];

    }


    return 0;
}
