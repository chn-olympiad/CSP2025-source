#include<bits/stdc++.h>
using namespace std;
int fun(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int arr[2000009],indexa=0;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0' && a[i]<='9'){
            arr[indexa]=a[i]-'0';
            indexa+=1;
        }
    }
    sort(arr,arr+indexa,fun);
    for(int i=0;i<indexa;i++){
        cout<<arr[i];
    }
    return 0;
}
