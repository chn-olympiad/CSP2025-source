#include<bits/stdc++.h>
using namespace std;
const int N=1E6+5;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","r",stdout);
    string s;
    int a[N]={0},t=1;
    cin>>s;
    for(int i=0;i<=s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[t]=s[i]-'0';
            t++;
        }
    }
    sort(a+1,a+t+1);
    for(int i=t;i>=2;i--){
        cout<<a[i];
    }
    return 0;
}
