#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    vector<long long>v;
    string s;
    cin>>s;
    for(auto &t:s){
        if (t=='1')v.push_back(1);
        else if (t=='2')v.push_back(2);
        else if (t=='3')v.push_back(3);
        else if (t=='4')v.push_back(4);
        else if (t=='5')v.push_back(5);
        else if (t=='6')v.push_back(6);
        else if (t=='7')v.push_back(7);
        else if (t=='8')v.push_back(8);
        else if (t=='9')v.push_back(9);
        else if (t=='0')v.push_back(0);
    }
    sort(v.begin(),v.end(),cmp);
    for(auto &p:v){
        cout<<p;
    }

    return 0;
}
