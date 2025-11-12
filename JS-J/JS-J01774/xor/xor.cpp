#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,num=0;
    cin>>n>>k;
    int a[n+1],i=1;
    while(i<=n){
        cin>>a[i];
	i++;
    }
    sort(a,a+n);
    int i=1,sum=0;
    while(i<=n){
        if(a[i]==k){
           num++;
            i++;
      }
        else{
            a[i]^=a[i];
            sum+=a[i];
            i++;
        }
        if(sum==k){
            sum=0;
            num++;
        }
    }
    cout<<num<<endl;
    return 0;
}
