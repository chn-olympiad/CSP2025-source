#include <bits/stdc++.h>
using namespace std;
int arr[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(!(s[i]>='a'&&s[i]<='z')){
            arr[(s[i]-'0')]++;
        }
    }
    for(int i=9;i>=0;i--){
        if(arr[i]!=0){
            for(int j=1;j<=arr[i];j++){
                cout<<i;
            }
        }
    }
    return 0;
}
