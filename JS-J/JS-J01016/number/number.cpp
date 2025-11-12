#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int arr[N];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int x=1;
    for(int i=0; i<s.size(); i++){
        if(s[i]<='9' && s[i]>='0'){
            arr[x]=int(s[i])-'0';
            x++;
        }
    }
    sort(arr+1, arr+x);
    for(int i=x-1; i>=1; i--){
        cout<<arr[i];
    }
    return 0;
}
