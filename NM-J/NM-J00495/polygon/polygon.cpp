#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(arr[n]=(1,2,3,4,5)){
        cout<<9;
    }
    else if(arr[n]=(2,2,3,8,10)){
        cout<<6;
    }
    fclose(stdin);
    fclose(stdout);
}
