#include<iostream>
#include<fstream>
using namespace std;

int m,tem;
int n,k,t;
int arr[500005];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        t=max(arr[i],t);
        m+=(arr[i]==0);
        tem+=(arr[i]==1);
    }
    if(t<2&&k==1){
        cout<<tem<<endl;
    }
    if(t<2&&!k){
        cout<<tem/2+m<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
