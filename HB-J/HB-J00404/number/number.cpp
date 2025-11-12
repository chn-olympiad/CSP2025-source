#include<bits/stdc++.h>
using namespace std;
string s;
long long num[1000001],n=0;
bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[n]=s[i]-48;
            n++;
        }
    }
    sort(num,num+n,cmp);
    if(num[0]==0){
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;i++){
        cout<<num[i];
    }
    return 0;
}
