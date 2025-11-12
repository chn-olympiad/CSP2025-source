#include <bits/stdc++.h>
using namespace std;
int num;
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("r","number.in",stdin);
    freopen("w","number.out",stdout);
    string s;
    int ans[10001];
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])) {num++;ans[num]+=s[i]-48;}
    }
    sort(ans+1,ans+num+1,cmp);
    for(int i=1;i<=num;i++){
        cout<<ans[i];
    }
    return 0;
}
