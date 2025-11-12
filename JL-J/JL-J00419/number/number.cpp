#include<bits/stdc++.h>
using namespace std;
long long a[100000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);//zhuwohaoyun
    string s;
    scanf("%f",s);
    for(int i=0;i<s.size();i++){
       for(int j=9;j>=0;j--){
            int c=s[i]%10;
            int d=j%10;
        if(c==d){
            cout<<s[i];
        }
       }
    }
    return 0;
}
