#include<iostream>
#include<cstdio>
using namespace std;

string s,a;
int b[305];
int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++) {
        if(s[i]>='0'&&s[i]<='9') {
            b[s[i]]++;
        }
    }
    for(int i='9';i>='0';i--) {
        while(b[i]!=0) {
            b[i]--;
            a=a+char(i);
        }
    }
    cout<<a;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
