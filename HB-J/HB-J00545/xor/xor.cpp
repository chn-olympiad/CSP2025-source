#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+7;
int n,k,sum=0;
int a[N];
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(k!=0){
        cout<<sum/k;
    }else{
        cout<<1;
    }
    return 0;
}
