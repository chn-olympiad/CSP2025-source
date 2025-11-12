#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+7;
string s;
string t;
vector<char> v;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            v.push_back(s[i]);
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        t+=v[i];
    }
    cout<<t<<"\n";
    return 0;
}
