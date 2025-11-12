#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[11]={0,0,0,0,0,0,0,0,0,0};
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    int f=0;
    for(int i=9;i>=0;i--){
        if(a[i]!=0&&i!=0){
            for(int j=1;j<=a[i];j++){
                cout<<i;
            }
            f=1;
        }else if(f&&a[i]!=0){
            for(int j=1;j<=a[i];j++)cout<<i;
        }else if(a[i]!=0){
            cout<<i;
        }
    }
    return 0;
}
