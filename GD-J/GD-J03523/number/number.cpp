#include<bits/stdc++.h>
using namespace std;

string s;
vector<int> R;

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(auto i:s){
        if(i>='0' && i<='9'){
            R.push_back(i-'0');
        }
    }
    sort(R.begin(),R.end(),cmp);
    for(auto i:R)  cout<<i;
    cout<<"\n";
    return 0;
}