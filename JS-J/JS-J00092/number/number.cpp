#include<bits/stdc++.h>
#define itn int
#define fro for
#define elif else if
#define endl "\n"
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using namespace std;
string s,ans="";
ll num[1006];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    IOS;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            num[s[i]-'0']++;
        }
    }
    //for(int i=0;i<=9;i++)cout<<num[i]<<" ";cout<<endl;
    for(int i=9;i>=0;i--){
        while(num[i]){
            cout<<i;
            num[i]--;
        }
    }
    return 0;
}
