#include <bits/stdc++.h>
using namespace std;
string s;
int n=0,arr[1000001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            arr[n]=s[i]-'0';
            n++;
        }
    }
    sort(arr,arr+n);
    for(int i=n-1;i>=0;i--){
        cout<<arr[i];
    }
    return 0;
}
