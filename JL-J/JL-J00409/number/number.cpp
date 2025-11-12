#include<bits/stdc++.h>
using namespace std;
string s;
int a[10000001];
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    int n;
    getline(cin,a[n]);
    int i=0;
    for(int j=0;j<=s.size();j++){
        if(s[j]=='0'||s[j]=='1'||s[j]=='2'||s[j]=='3'||s[j]=='4'||s[j]=='5'||s[j]=='6'||s[j]=='7'||s[j]=='8'||s[j]=='9'){
            a[n]==s[j];
            n++;
        }
    }

    cout<<a[i];
    return 0;
}
