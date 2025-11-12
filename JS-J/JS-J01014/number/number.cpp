#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int num[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int t=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[t]=s[i]-'0';
            t++;
        }
    }
    sort(num,num+t);
    int a=0;
    for(int i=t-1;i>=0;i--){
        a+=pow(10,i)*num[i];
    }
    cout<<a;
    return 0;
}
