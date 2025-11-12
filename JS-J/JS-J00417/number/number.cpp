#include<bits/stdc++.h>
using namespace std;
#define int long long

string s;
int a[100];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        if(a[i]!=0){
            for(int j=1;j<=a[i];j++){
                cout<<i;
            }
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}

