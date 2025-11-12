#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[10001]={0},j=1;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[j]=s[i]-'0';
            j++;
        }
    }
    for(int h=1;h<=j;h++){
        for(int i=1;i<=j;i++){
            if(a[i]<a[i+1]){
                int x=a[i];
                a[i]=a[i+1];
                a[i+1]=x;
            }
        }
    }
    for(int i=1;i<j;i++){
        cout<<a[i];
    }
    return 0;
}
