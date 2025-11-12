#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000666];
int sum;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>=97&&s[i]<=122){
            continue;
        }
        if(s[i]>=48&&s[i]<=57){
            a[i]=s[i]-'0';
            sum++;
        }
    }
    cout<<sum<<"\n";
    sort(a,a+sum+10000,cmp);
    if(a[1]==0){
        cout<<0;
        return 0;
    }
    for(int i=0;i<sum;i++){
        cout<<a[i];
    }
    return 0;
}
