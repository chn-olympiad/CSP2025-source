#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[1000050];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int l=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[l++]=s[i]-'0';
        }
    }
    sort(a,a+l,cmp);
    for(int i=0;i<l;i++){
        cout<<a[i];
    }
    return 0;
}
