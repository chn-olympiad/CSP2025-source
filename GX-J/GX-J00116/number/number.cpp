#include<bits/stdc++.h>
using namespace std;
string n;
vector<int> a;
int main(){

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    for(int i=0;i<n.size();i++){
        if(n[i]>='0'&&n[i]<='9'){
            int l=n[i]-'0';
            a.push_back(l);
        }
    }
    sort(a.begin(),a.end());
    for(int i=a.size()-1;i>=0;i--){
        cout<<a[i];
    }

    return 0;
}
