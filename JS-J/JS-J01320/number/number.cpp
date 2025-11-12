#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
string s;
int n,num[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s;
    n=s.size();
    s=' '+s;
    for(int i=1;i<=n;i++){
        int id=s[i]-'0';
        if(id>=0&&id<=9) num[id]++;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=num[i];j++) cout<<i;
    }
    return 0;
}
