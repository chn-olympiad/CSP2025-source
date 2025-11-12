#include <bits/stdc++.h>
using namespace std;
string s;
int a[1005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int m=-1;
    for(int i=0;i<s.size();i++){
        int x=s[i]-'0';

        if(x<=9&&x>=0){
            //cout<<x;
            a[x]++;
            m=max(m,x);
        }
    }
    int i=m;
    while(i>=0){
        if(a[i]){
            while(a[i]--)cout<<i;
        }
        i--;
    }
    return 0;
}