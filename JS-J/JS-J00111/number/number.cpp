#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 7;
string s;
int num[MAXN];
int tot;
bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            num[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=num[i];j++){
            cout<<i;
        }
    }
    cout<<endl;
    return 0;
}
