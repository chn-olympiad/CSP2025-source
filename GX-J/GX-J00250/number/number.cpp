#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int ans,n=0,z,p=1;
    char a[100004];
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
       if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
            n++;
            a[n]=s[i];
       }
    }
    while(p==1){
        p=0;
        for(int i=2;i<=n;i++){
            if(a[i]>a[i-1]){
                z=a[i-1];
                a[i-1]=a[i];
                a[i]=z;
                p=1;
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<a[i];
return 0;
}

