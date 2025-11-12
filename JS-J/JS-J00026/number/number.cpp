#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string str,num;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>str;
    n=str.size();
    for(int i=0;i<n;i++){
        if('0'<=str[i]&&str[i]<='9') num+=str[i];
    }
    sort(num.begin(),num.end());
    for(int i=num.size()-1;i>=0;i--){
        cout<<num[i];
    }
    cout<<'\n';
    return 0;
}
