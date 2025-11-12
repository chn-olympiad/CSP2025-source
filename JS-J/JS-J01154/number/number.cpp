#include<bits/stdc++.h>
using namespace std;
int ans[10];
int main(){
    freopen("number3.in","r",stdin);
    freopen("number3.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char c;
    while(cin>>c){
        if(c>='0'&&c<='9')ans[c-'0']++;
    }
    for(int i=9;i>=0;i--){
        while(ans[i]--)cout<<i;
    }
    return 0;
}
