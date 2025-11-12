#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int j=0;
int a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            j++;
            a[j]=s[i]-'0';
        }
    }
    sort(a+1,a+j+1);
    for(int i=j;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
