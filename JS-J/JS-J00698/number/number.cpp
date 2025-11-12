#include<bits/stdc++.h>
using namespace std;
int arr[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int t=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            arr[++t]=s[i]-'0';
        }
    }
    sort(arr+1,arr+1+t);
    if(arr[t]=='0'){
        cout<<0;
        return 0;
    }
    for(int i=t;i>=1;i--){
        cout<<arr[i];
    }
    return 0;
}
