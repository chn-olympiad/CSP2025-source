#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int a[100],n=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[n]=s[i]-'0';
            n++;
        }

    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
