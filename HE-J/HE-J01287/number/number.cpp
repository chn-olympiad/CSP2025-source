#include<bits/stdc++.h>
using namespace std;
string s;
int n;
char a[1000005];
bool cmp(char a,char b) {
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.ans","w",stdout);
    cin>>s;
    s=' '+s;
    for(int i=1;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[n++]=s[i];
        }
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        cout <<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
