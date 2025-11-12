#include<bits/stdc++.h>
using namespace std;
string s;
int a[100010],n=0,ans[100010],x,j=1;
bool sm(int g,int h){
    return g>h;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    int len=s.size();
    for(int i=0;i<=len;i++){
        if(s[i]>=49 and s[i]<=59){
            a[n]=s[i]-48;
            n++;
        }
    }
    sort(a,a+n,sm);
    for(int i=0;i<=n-1;i++){
        cout<<a[i];
    }
    return 0;
}
