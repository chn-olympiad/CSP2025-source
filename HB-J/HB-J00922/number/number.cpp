#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int b;
    for(int i=0;i<a.size();i++){
        b=0;
        if(a[i]>='0'&&a[i]<='9'){
            if(a[i]-48>=b){
                b=a[i]-48;
            }
        }
        if(b==0&&i==0){
            cout<<0;
            return 0;
        }
        else cout<<b;
    }
    return 0;
}
