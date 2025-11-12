#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    cin>>str;
    int l=str.size(),k=0;
    int arr[l]={0};
    for(int i=0;i<l;i++){
        if(str[i]>='0'&&str[i]<='9'){
            arr[k++]=str[i]-'0';
        }
    }
    sort(arr,arr+k,cmp);
    for(int i=0;i<k;i++){
        cout<<arr[i];
    }
    return 0;
}