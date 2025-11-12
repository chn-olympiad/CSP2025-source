#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int j=0;
    string a;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            a[j]=s[i];
            j++;
        }
    }
    for(int m=0;m<j;m++){
        for(int i=0;i<j;i++){
            if(a[i]<a[i+1]){
                char b=a[i];
                a[i]=a[i+1];
                a[i+1]=b;
            }
        }
    }
    for(int i=0;i<=j;i++){
        if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'){
            cout<<a[i];
        }
    }
    return 0;
}

