#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int a[N],n;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int x=strlen(s);
    for(int i=0;i<x;i++){
        if(s[i]>='0'&&s[i]<='9') a[++n]=s[i]-'0';
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--)  cout<<a[i];
    cout<<endl;
    return 0;
}
