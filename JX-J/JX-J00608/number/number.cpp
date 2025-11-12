#include<bits/stdc++.h>
using namespace std;
int arr[1000001];
int power(int a,int b){
    int t=1;
    for(int i=1;i<=b;i++){
        t*=a;
    }
    return t;
}
int main(){
 //   freopen("number.in","r",stdin);
 //   freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int k=1,ans=0,s;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            arr[k]=a[i]-48;
            k++;
        }
    }
    sort(arr+1,arr+k);
    for(int i=k-1;i>=1;i--){
        cout<<arr[i];
    }
    return 0;
}
