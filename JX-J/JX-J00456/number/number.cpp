#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
  int a[N];
int main(){

    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        if(a[i]>a[i+1]){
            cout<<a[i];

        }
        else{
            cout<<a[i+1];

        }
    }

    return 0;
}
