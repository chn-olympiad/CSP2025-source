#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char c;
    string s;cin>>s;
    int cd=s.length();
    int a[1005]={0};
    int j=0;
    for(int i=0;i<cd;i++){
        c=s[i];
        if(c>='0'&& c<='9'){
            a[j]=int(c-'0');
            j++;
        }
    }
    sort(a,a+j);
    for(int i=j-1;i>=0;i--){
        cout<<a[i];
    }
}
