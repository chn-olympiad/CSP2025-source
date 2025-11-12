#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001];

int main(){
    int j = 0;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i = 0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i] = s[i];
        }
    }
    sort(a,a+s.length());
    for(int i = s.length();i>0;i--){
        cout<<(char)a[i];
    }
}
