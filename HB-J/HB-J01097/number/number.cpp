#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
const int N=1e5+5;
str s;
int a[11];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        if(a[i]==0)continue;
        for(int j=1;j<=a[i];j++)cout<<i;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}