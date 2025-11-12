#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
        return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    unsigned long long ls=s.size();
    unsigned long long a[ls+5]={0};
    unsigned long long g=0;
    for(unsigned long long i=0;i<ls;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[g]=s[i]-'0';
            g++;
        }
    }
    sort(a,a+g,cmp);
    for(unsigned long long i=0;i<g;i++){
        cout<<a[i];
    }
    return 0;
}
