#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int mx=1e6+5;
vector <int> a;
string s;
inline bool isnum(char s){
    if('0'<=s && s<='9') return true;
    return false;
}
inline bool cmp(int a,int b){
    return a>b;
}
//finally have a check because of its "inline"
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>s;
    for(char i:s){
        if(isnum(i)){
            a.push_back(i-'0');
        }
    }
    sort(a.begin(),a.end(),cmp);
    if(a[0]==0) printf("0");
    else{
        for(int u:a){
            printf("%d",u);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
