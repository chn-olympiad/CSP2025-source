#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int len,x=0;
    char a[100005];
    cin>>s;
    len=s.size();
    for(int i=0;i<len;i++){
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            a[x]=s[i];
            x++;
        }
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<len-1;j++){
            if(a[j]<a[j+1]){
                int b=a[j];
                a[j]=a[j+1];
                a[j+1]=b;
            }
        }
    }
    for(int i=0;i<len;i++){
        cout<<a[i];
    }
    return 0;
}
