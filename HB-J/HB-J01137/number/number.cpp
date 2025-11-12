#include <bits/stdc++.h>
using namespace std;
string s;
int a[100005],cnt=0;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i=0;s[i];i++){
        if('0'<=s[i]&&s[i]<='9'){
            a[cnt++]=s[i]-'0';
        }
    }
    sort(a,a+cnt,cmp);
    for(int i=0;i<cnt;i++){
        cout << a[i];
    }
    return 0;
}
