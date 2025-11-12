#include<bits/stdc++.h>
using namespace std;

string s;
int arr[1000005];
int ind=0;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(c>='0' && c<='9'){
            int t=c-'0';
            arr[ind++]=t;
        }
    }
    sort(arr,arr+ind);
    for(int i=ind-1;i>=0;i--){
        cout<<arr[i];
    }
    cout<<endl;
    return 0;
}
