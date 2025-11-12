#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int b=s.size();
    int c=0;
    for(int i=0;i<b;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        if(a[i]>0){
            for(int j=0;j<a[i];j++){
                cout<<i;
            }
        }
    }
}
