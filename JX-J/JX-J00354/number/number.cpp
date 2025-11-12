#include<bits/stdc++.h>
using namespace std;

string s;
char a[1000001];
int r;
char cnt(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    int l=s.size();
    for(int i=0;i<l;i++){
        r = (int)(s[i]);
        if(r >= 48 && r <= 57){
            a[i] = s[i];
        }
    }
    sort(a,a+l,cnt);
    for(int i=0;i<l;i++){
        cout<<a[i];
    }
    return 0;
}
