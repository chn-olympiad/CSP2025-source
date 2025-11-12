#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
bool f;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[int(s[i]-48)]++;
        }
    }
    for(int i=9;i>=1;i--){
        if(a[i]!=0){
            for(int j=1;j<=a[i];j++){
                cout<<i;
            }
            f=1;
        }
    }
    if(f){
        for(int i=1;i<=a[0];i++){
            cout<<0;
        }
    }
    else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
