#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,m,j,k,l=1,lie,hang;
    cin>>n>>m;
    cin>>j;
    for(int i=0;i<n*m-1;i++){
        cin>>k;
        if(k>j){
            l++;
        }
    }
    lie=ceil((l/1.0)/m);
    hang=l-(lie-1)*n;
    if(lie%2==0){
        hang=n-hang+1;
    }
    cout<<lie<<' '<<hang;
    return 0;}
