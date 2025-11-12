#include<bits/stdc++.h>
using namespace std;
string s;
int arr[1000005],k;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            k++;
            arr[k]=s[i]-48;
        }
    }
    sort(arr+1,arr+k+1,cmp);
    for(int i=1;i<=k;i++){
        cout<<arr[i];
    }
    return 0;
}
