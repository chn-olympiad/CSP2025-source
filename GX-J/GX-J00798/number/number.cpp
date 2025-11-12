#include<bits/stdc++.h>
using namespace std;
bool hs(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    long long b[a.length()+4]={0},c=0;
    for(int i=0;i<a.length();i++){
        if(a[i]<='9'&&a[i]>='0'){
            b[i]=a[i]-'0';
        }else c++;
    }
    sort(b,b+a.length(),hs);
    for(int i=0;i<a.length()-c;i++){
            if(i==0&&b[i]==0) {
            }else{
                cout<<b[i];
            }
    }
    return 0;
}
