#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int MAX=arr[0];
    for(int a=0;a<n;a++){
        if(MAX<arr[a+1]){
            MAX=arr[a+1];
        }
    }
    cout<<MAX;
    fclose(stdin);
    fclose(stdout);
}
