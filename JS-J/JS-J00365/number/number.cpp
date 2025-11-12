#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int cnt,arr[N];
string str;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>str;
    for(int i=0;i<str.size();i++){
        if(str[i]>='0'&&str[i]<='9'){
            arr[++cnt]=str[i]-'0';
        }
    }
    sort(arr+1,arr+1+cnt);
    for(int i=cnt;i>=1;i--){
        cout<<arr[i];
    }
    return 0;
}
