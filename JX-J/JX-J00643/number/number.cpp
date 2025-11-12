#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    int a[100];
    int x=1;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9' || s[i]=='0'){
            a[x]=s[i]-'0';
            x++;
        }
    }
    sort(a+1,a+x);
    for(int i=x-1;i>=1;i--){
        if(a[x-1]==0){
            cout<<0;
            return 0;
        }
        cout<<a[i];
    }
    return 0;
}

