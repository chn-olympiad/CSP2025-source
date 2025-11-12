#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n,q,ans;
string s1[N];
string s2[N];
bool f(string x,string y,int a){
    for (int i = 0;i <= x.size();i++){
        if (s1[a].size() > x.size()){
            return false;
        }
        bool flag = 0;
        for (int j = 0;j < s1[a].size();j++){
            if (s1[a][j] != x[i+j]){
                flag = 1;
                break;
            }
        }
        if (flag == 1){
            continue;
        }
        for (int j = 0;j < s2[a].size();j++){
            if (s2[a][j] != y[i+j]){
                flag = 1;
                break;
            }
        }
        if (flag == 1){
            continue;
        }
        for (int j = 0;j < x.size() - i - s1[a].size();j++){
            if (x[i + j + s1[a].size()] != y[i + j + s1[a].size()]){
                flag = 1;
                continue;
            }
        }
        for (int j = 0;j < i;j++){
            if (x[j] != y[j]){
                flag = 1;
                continue;
            }
        }
        if (flag != 1){
            return true;
        }
    }
    return false;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for (int i = 1;i <= n;i++){
        cin>>s1[i]>>s2[i];
    }
    while (q--){
        ans = 0;
        string x,y;
        cin>>x>>y;
        for (int i = 1;i <= n;i++){
            if (f(x,y,i) == true){
                ans++;
            }
        }
        printf("%d",ans);
    }
    return 0;
}