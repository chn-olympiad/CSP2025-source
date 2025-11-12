#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[1000001],l=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i] && s[i]<='9'){
            a[++l]=s[i]-'0';
        }
    }
    sort(a+1,a+1+l);
    for(int i=l;i>=1;i--){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
