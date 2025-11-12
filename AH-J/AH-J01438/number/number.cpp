#include<bits/stdc++.h>
using namespace std;
long long a[100000000];
string s;
long long cmp(long long a,long long b){
    return a>b;
}
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    cin>>s;
    long long m=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[m]=s[i]-'0';
            m++;
        }
    }
    sort(a,a+m,cmp);
    for(int i=0;i<m;i++){
        cout<<a[i];
    }
    return 0;
}
