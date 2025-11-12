#include<bits/stdc++.h>
using namespace std;
int a[1000006];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size();
    int c=0;
    for(int i=0;i<=n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[c++]=s[i]-48;
        }
    }
    sort(a+0,a+c,cmp);
    for(int i=0;i<c;i++){
        cout<<a[i];
    }
    return 0;
}
