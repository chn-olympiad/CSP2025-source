#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;
int arr[M];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int k=0;
    cin>>a;
    for(int i=0;i<a.length();i++)if('0'<=a[i]&&a[i]<='9')arr[k++]=a[i]-'0';
    sort(arr,arr+k,cmp);
    for(int i=0;i<k;i++)cout<<arr[i];
    return 0;
}
