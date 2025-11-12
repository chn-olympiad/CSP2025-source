#include<bits/stdc++.h>
using namespace std;
int r[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=0,j=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            r[j]=s[i]-48;
            n++;
            j++;
        }
    }

    sort(r,r+n);
    for(int i=n-1;i>=0;i--){
        cout<<r[i];
    }
    return 0;
}
