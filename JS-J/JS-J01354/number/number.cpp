#include<bits/stdc++.h>
using namespace std;
#define please return
#define AC 0
long long k[10];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    for(int i=0;i<s.size();i++)if(s[i]>='0'&&s[i]<='9')k[int(s[i]-'0')]++;
    for(int i=9;i>=0;i--){
        for(int j=0;j<k[i];j++){
            cout<<i;
        }
    }
    please AC;
}
