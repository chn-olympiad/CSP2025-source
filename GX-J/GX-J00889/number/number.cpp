#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    int a[1000006],l=0,k=0;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]==1+'0'||s[i]==2+'0'||s[i]==3+'0'||s[i]==4+'0'||s[i]==5+'0'||s[i]==6+'0'||s[i]==7+'0'||s[i]==8+'0'||s[i]==9+'0'||s[i]==0+'0'){
            a[l]=s[i]-'0';
            l++;
        }
    }
    sort(a,a+l);
    for(int i=l-1;i>=0;i--){
        cout<<a[i];
    }


    return 0;
}
