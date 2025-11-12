#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int len = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[len] = s[i]-'0';
            len++;
        }
    }
    sort(a,a+len);
    for(int i=len-1;i>=0;i--){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
