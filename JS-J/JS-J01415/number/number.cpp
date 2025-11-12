#include<bits/stdc++.h>
using namespace std;
long long a[15];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        int l=s[i]-'0';
        if(l>=0&&l<=9)a[l]++;
    }
    if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]==0)cout<<0;
    else {
        for(int i=9;i>=0;i--)
            for(int j=1;j<=a[i];j++)printf("%d",i);
    }

    return 0;
}
