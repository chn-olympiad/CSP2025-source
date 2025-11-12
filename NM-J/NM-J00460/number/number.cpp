#include<bits/stdc++.h>
using namespace std;
int main(){
//#ifndef OFFLINE_JUDGE
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
//#else
//freopen("/home/noi/J/number/number2.in","r",stdin);
//freopen("/home/noi/J/number/number2.out","w",stdout);
//#endif // OFFLINE_JUDGE
    vector<int>v;
    char c;
    while(cin>>c){
        if('0'<=c&&c<='9'){
            //cout<<c;
            v.push_back(c-'0');
        }
    }
    cout<<endl;
    sort(v.rbegin(),v.rend());
    for(int i:v){
        cout<<i;
    }
    return 0;
}
