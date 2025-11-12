#include <bits/stdc++.h>
using namespace std;
bool b(int x,int y){
    if(x>y){
        return true;
    }else{
        return false;
    }
};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[10000]={},n=0;
    cin>>s;
    if(s.size()==1){
        cout<<s;
        return 0;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            a[i]=int(s[i]);
            n++;
        }
    }
    sort(a,a+n,b);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
}
