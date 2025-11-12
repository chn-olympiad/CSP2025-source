#include <bits/stdc++.h>
using namespace std;
int num[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    int cnt=0;
    for (int i=0;i<(int)s.size();i++){
        if (s[i]>='0' && s[i]<='9'){
            cnt++;
            num[cnt]=s[i]-'0';
        }
    }
    sort(num+1,num+cnt+1);
    for (int i=cnt;i>=1;i--){
        cout<<num[i];
    }
    return 0;
}
