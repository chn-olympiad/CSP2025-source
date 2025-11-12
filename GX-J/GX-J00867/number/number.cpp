#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+5;
int a[N];
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int jian=0;
    int ze=0;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            if(s[i]=='0')ze++;
            jian++;
            a[jian]=s[i]-'0';
        }
    }
    if(ze==jian){
        cout<<0;
        return 0;
    }
    sort(a+1,a+jian+1,cmp);
    for(int i=1;i<=jian;i++)cout<<a[i];
    return 0;
}
