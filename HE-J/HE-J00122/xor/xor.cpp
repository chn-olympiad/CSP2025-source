#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,k,a[1048576]={},t=0,h=0,j=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    while(t<n){
        h=a[t];
        while(t<n){
            if(h==k){
                j++;
                t++;
                break;
            }
            else{
                t++;
                h=h^a[t];
            }
        }
    }
    cout<<j;

    return 0;}
