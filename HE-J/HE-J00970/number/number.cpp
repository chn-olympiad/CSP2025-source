#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(char x,char y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    char shu[1000001];
    int n=0;
    cin>>s;
    for(int i=0;i<s.size();++i){
        if(s[i]>='0'&&s[i]<='9'){
            shu[n]=s[i];
            ++n;
        }
    }
    sort(shu,shu+n,cmp);
    for(int i=0;i<n;++i){
        cout<<shu[i];
    }
    return 0;
}
