#include<bits/bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freoprn("number.out","w",stdout);
    string s=' ';
    cin>>s;
    char t;
    int cnt=0;
    string a;
    while(t--){
        cnt++;
        if(s[cnt]>='1'&&s[cnt]<='9'){
            t=s[cnt];
        }
        (char)a+=(char)t;
        if(cnt<=s.size()){
            break;
        }
    }
    for(int i=0;i<a.size();i++){
        for(int j=i+1;j<a.size();j++){
            if(a[i]>a[j]){
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    for(int i=0;i<a.size();i++){
        if(a[i]==a[i+1]&&a[i]!=a[i+2]){
            cout<<a[i];
        }
    }
    return 0;
}
