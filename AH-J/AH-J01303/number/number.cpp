#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        int k=s[i]-'0';
        if(k>=0&&k<=9){
            a[k]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=a[i];j>=1;j--){
            printf("%d",i);
        }
    }
    return 0;
}
