#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int num;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'>=0 && s[i]-'0'<=9){
            num++;
            a[num]=s[i]-'0';
        }
    }
    sort(a+1,a+num+1);
    for(int i=num;i>=1;i--){
        printf("%d",a[i]);
    }
    return 0;
}

