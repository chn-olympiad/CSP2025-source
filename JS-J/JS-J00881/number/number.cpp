#include<bits/stdc++.h>
using namespace std;
long long a[10][2];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int lens=s.size();
    for(int i=0;i<lens;i++){
        if('0'<=s[i] && s[i]<='9'){
            a['9'-s[i]][1]++;
        }
    }
    for(int i=0;i<=9;i++){
        while(a[i][1]!=0){
            cout<<9-i;
            a[i][1]--;
        }
    }
    return 0;
}

