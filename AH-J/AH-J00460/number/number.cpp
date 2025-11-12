#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    std::cin>>s;
    int n=s.size();
    int t=0,f=0;
    for(int i=0;i<n;i++){
        if(s[i]>='1' && s[i]<='9'){
            a[f]+=s[i]-'1'+1;
            f++;
        }else if(s[i]=='0'){
            t++;
        }
    }
    sort(a,a+f,greater<int>());
    for(int i=0;i<f;i++){
        std::cout<<a[i];
    }
    for(int i=0;i<t;i++){
        std::cout<<"0";
    }
    return 0;
}
