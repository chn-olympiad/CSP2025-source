#include <bits/stdc++.h>
using namespace std;

string s;
int tong[10];

bool check(char x){
    if('0'<=x&&x<='9') return 1;
    else return 0;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.ans","w",stdout);
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
        if(check(s[i])) tong[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        if(tong[i]!=0){
            for(int j=1;j<=tong[i];j++) cout<<i;
        }
    }
    return 0;
}

