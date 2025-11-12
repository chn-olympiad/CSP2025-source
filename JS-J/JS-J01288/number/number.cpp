#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[s.size()];
    int k=0;
    for(int i=0;i<s.size();i++){
        a[i]=-1;
    }
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            a[k]=(int)s[i]-48;
            k++;
        }
    }
    sort(a,a+s.size());
    for(int i=s.size()-1;i>=0;i--){
        if(a[i]!=-1)
            cout<<a[i];
    }
    return 0;
}
