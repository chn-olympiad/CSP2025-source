#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin >> a;
    vector<int> number={};
    long long len=a.size();
    for(int i=0;i<len;i++){
        if(a[i]>=48&&a[i]<=57){
            number.push_back(a[i]-'0');
        }
    }
    sort(number.begin(),number.end(),cmp);
    if(number[0]==0){
        cout << 0;
        return 0;
    }
    for(auto x:number){
        cout << x;
    }
    return 0;
}
