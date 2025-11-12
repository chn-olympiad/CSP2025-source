#include<bits/stdc++.h>
using namespace std;
int n,a=0,m=0,s=0;
int arr[5005];
int brr[1005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        brr[arr[i]]++;
        a=max(a,arr[i]);
    }
    for(int i=1;i<=a;i++){
        if(brr[i]>=1)m++;
        if(brr[i]>1){
            for(int j=brr[i]-1;j>=1;j++)s+=j;
        }
    }
    for(int j=m-1;j>=1;j--)s+=j;
    cout<<s;
    return 0;
}
