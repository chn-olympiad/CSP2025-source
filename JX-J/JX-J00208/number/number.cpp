#include<bits/stdc++.h>
using namespace std;
int a[1000010];
string s;
int c=0,j=1;
int main(){

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('9'>=s[i]&&s[i]>='0'){
            a[j]=s[i]-'0';
            j++;
        }
    }
    sort(a+1,a+1+j);
    for(int i=j;i>1;i--){
        cout<<a[i];
    }
    return 0;
}
