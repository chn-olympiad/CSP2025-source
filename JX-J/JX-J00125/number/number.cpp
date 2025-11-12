#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

string s;
int ma[15];
int main(){
    IOS;

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
        if('0'<=s[i]&&s[i]<='9'){
            ma[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=ma[i];j++){
            cout<<i;
        }
    }
    return 0;
}















