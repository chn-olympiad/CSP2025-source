#include<bits/stdc++.h>
#define ll long long
using namespace std;
int book[11];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int len=s.size();
    int k=0;
    for(int i=0;i<len;i++){
        if(isdigit(s[i])){
            book[s[i]-'0']++;
        }
    }
    string sum="";
    for(int i=9;i>=0;i--){
        for(int j=1;j<=book[i];j++)
            sum+=(char)(i+'0');
    }
    while(sum[0]=='0'&&sum.size()>1)
        sum.erase(0,1);
    cout<<sum<<'\n';
    return 0;
}
