#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    char c[1000005];int i=0,n=0;
    cin>>s;
    for(i;i<s.size();i++){
       if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            c[n]=s[i];
            n++;
        }
    }
    sort(c,c+n);
    for(int j=n;j>=0;j--){
        cout<<c[j];
    }
    return 0;
}
