#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>=b;
}
map<char,long long>cnt;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string a;
    cin>>a;
    //vector<char>cnt;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            cnt[a[i]]++;
        }
    }
    for(char i='9';i>=0;i--){
        for(int j=0;j<cnt[i];j++){
            printf("%c",i);
        }
    }
    return 0;
}
