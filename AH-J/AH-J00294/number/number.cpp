//number.cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
string s;
char a[N];
int x;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            x++;
            a[x]=s[i];
        }
    }
    sort(a+1,a+1+x);
    for(int i=x;i>=1;i--) printf("%c",a[i]);
    return 0;
}
