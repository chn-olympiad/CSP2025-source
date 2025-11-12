#include<bits/stdc++.h>
using namespace std;
int a[1000001],n=1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[n]=s[i];
            n++;
        }
    }
    for(int i=1;i<n;i++){
        a[i]-=48;
    }
    sort(a+1,a+n);
    for(int i=n-1;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
