#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],b[1000005],ans;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]=='0'){
            ans++;
        }else if(s[i]=='1'){
            a[i]=1;
        }else if(s[i]=='2'){
            a[i]=2;
        }else if(s[i]=='3'){
            a[i]=3;
        }else if(s[i]=='4'){
            a[i]=4;
        }else if(s[i]=='5'){
            a[i]=5;
        }else if(s[i]=='6'){
            a[i]=6;
        }else if(s[i]=='7'){
            a[i]=7;
        }else if(s[i]=='8'){
            a[i]=8;
        }else if(s[i]=='9'){
            a[i]=9;
        }
    }
    int j=0;
    for(int i=0;i<len;i++){
        if(a[i]!=0) {
            b[j]=a[i];
            j++;
        }
    }
    sort(b,b+j);
    for(int i=j-1;i>=0;i--) cout<<b[i];
    for(int x=1;x<=ans;x++) cout<<0;
    return 0;
}