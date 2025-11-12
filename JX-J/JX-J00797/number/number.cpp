#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[100000];
    cin>>s;
    int b=0;
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'>=0 && s[i]-'0'<=9){
            a[b]=s[i]-'0';
            b++;
        }else{
            continue;
        }
    }
    sort(a,a+b);
    for(int i=b;i>0;i--){
        cout<<a[i-1];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
