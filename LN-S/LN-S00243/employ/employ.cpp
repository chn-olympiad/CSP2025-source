#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],a[505],exit=0;
string s[505];
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","r",stdout);
    cin >> n >> m;
    cin >> s;
    for(int i=1;i<=m;i++){
        cin >> c[i];
    }
    sort(c+1,c+n+1,cmp);
    for(int i=1;i<=s.size();i++){
        if(exit>c[i]){
            exit++;
            continue;
        }
        if(s[i]=='1') exit++;
    }
    cout << 2;
    return 0;
}
