#include<bits/stdc++.h>
using namespace std;
string s;
int const N=1e5+10;
int a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        a[i]=-1;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='1')a[i]=1;
        if(s[i]=='2')a[i]=2;
        if(s[i]=='3')a[i]=3;
        if(s[i]=='4')a[i]=4;
        if(s[i]=='5')a[i]=5;
        if(s[i]=='6')a[i]=6;
        if(s[i]=='7')a[i]=7;
        if(s[i]=='8')a[i]=8;
        if(s[i]=='9')a[i]=9;
        if(s[i]=='0')a[i]=0;
    }
    sort(a,a+s.size());
    for(int i=s.size()-1;i>=0;i--){
        if(a[i]==-1)break;
        cout<<a[i];
    }
    return 0;
}
