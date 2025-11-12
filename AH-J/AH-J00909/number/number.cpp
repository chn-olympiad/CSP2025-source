#include<bits/stdc++.h>
using namespace std;
int a[1000005],in=1;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
           int t=s[i]-'0';
           a[in]=t;
           in++;
        }
    }
    sort(a+1,a+in);
    if(a[in-1]==0){
       cout<<0;
       return 0;
    }
    for(int i=in-1;i>=1;i--){
        printf("%d",a[i]);
    }
    return 0;
}
