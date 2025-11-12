#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int len=s.size();
    int n=0;
    for(int i=0;i<len;i++){
        if(s[i]>='0' && s[i]<='9'){
            a[n]=s[i]-48;
            n++;
        }
    }
    sort(a,a+n,greater<int>());
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
}
