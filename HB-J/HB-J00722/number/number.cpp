#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int c=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'>=0&&s[i]-'0'<10){
            a[c]=s[i]-'0';
            c++;
        }
    }
    sort(a,a+c);
    for(int i=c-1;i>=0;i--){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}