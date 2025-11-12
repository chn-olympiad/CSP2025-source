#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int k;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
            a[k++]=int(s[i])-48;
        }

    }
    sort(a,a+k,cmp);
    for(int i=0;i<k;i++){
        cout<<a[i];
    }
    return 0;
}
