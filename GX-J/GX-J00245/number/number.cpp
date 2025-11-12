#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int i,n,a[10]={};
    cin>>s;
    for(i=0;i<s.size();i+=1){
        n=s[i]-'0';
        if(n>=0&&n<=9){
            a[n]+=1;
        }
    }
    for(i=9;i>=0;i-=1){
        while(a[i]>0){
            cout<<i;
            a[i]-=1;
        }
    }
    cout<<endl;
    return 0;
}
