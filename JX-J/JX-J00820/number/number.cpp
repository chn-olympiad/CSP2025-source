#include <bits/stdc++.h>
using namespace std;
string a,s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size();i++){
        if(s[i]>=48&&s[i]<=57){
            a+=s[i];
        }
    }
    for(int i=0;i<=a.size()-1;i++){
        bool flag=true;
        for(int j=0;j<=a.size()-i-1;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
                flag=false;
            }
        }
        if(flag==true) break;
    }
    cout<<a;
    return 0;
}
