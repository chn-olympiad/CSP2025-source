#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    char s[1000001];
    cin>>a;
    int k=1;
    sort(a.begin(),a.end());
    for(int i=0;i<=a.size()-1;i++){
        if(a[i]>=48&&a[i]<=57){
            s[k]=a[i];
            k++;
        }
    }
    for(int i=a.size();i>=0;i--){
        cout<<s[i];
    }
    return 0;
}
