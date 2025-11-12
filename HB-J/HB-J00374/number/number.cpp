#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[1000000],n=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[n]=s[i]-'0';
            n++;
        }
    }
    sort(a,a+n,cmp);
    if(a[0]==0){
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
}
