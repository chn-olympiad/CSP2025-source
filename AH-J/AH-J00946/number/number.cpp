#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[100]={0};
    int n=0;
    for(int i=0;i<=s.size()-1;i++){
        cin>>s[i];
    }
    for(int i=0;i<=s.size()-1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=s[i];
            n++;
        }
    }
    sort(a,a+n);
    for(int i=0;i<=n-1;i++){
        cout<<a[i];
    }
    return 0;
}
