#include<bits/stdc++.h>
using namespace std;
int a[1000001],rear=0;
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9' and s[i]>='0'){
            rear++;
            a[rear]=s[i]-'0';
        }
    }
    sort(a+1,a+rear+1);
    if(a[rear]==0) cout<<'0';
    else{
        for(int i=rear;i>=1;i--){
            cout<<a[i];
        }
    }
    return 0;
}
