#include<bits/stdc++.h>
using namespace std;
int a[1000001],j,n,i;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[j]=s[i]-'0';
            j++;
        }
    }
    for(i=0;i<j-1;i++){
        for(n=0;n<j-i-1;n++){
            if(a[n]<a[n+1]){
                swap(a[n],a[n+1]);
            }
        }
    }
    for(i=0;i<j;i++){
        cout<<a[i];
    }
    return 0;
}
