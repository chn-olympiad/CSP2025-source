#include<bits/stdc++.h>
#include<string>
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
using namespace std;
int main(){
    string s;
    cin>>s;
    int a[1000010],j=0;
    for(int i=0;i<s.length();i++){
        if(s[i]-48>=0 && s[i]-48<=9){
            a[j]=s[i];
            j++;
        }
    }
    for(int i=0;i<=j;i++){
            for(int k=i+1;k<=j;k++){
                if(a[k]>a[i]){
                int max=a[k];
                a[k]=a[i];
                a[i]=max;
            }
        }
    }
    for(int i=0;i<j;i++)
        cout<<a[i]-'0';
    return 0;
}
