#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
int a[1000001],tot=1;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[tot]=s[i]-48;
            tot++;
        }
    }
    tot--;
    sort(a+1,a+tot+1);
    for(int i=tot;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
