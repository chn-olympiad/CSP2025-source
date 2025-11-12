#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
long long n,rec,a,sum=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
cin>>n>>a;
for(int i=0;i<n;i++)
    for(int j=0;j<a;j++){
        if(i==j){
            rec+=(a-i)%(a-j);
        }else{
            rec+=(n+i)%(n-j);
            sum++;
    }
    if(i==j-1){
        rec+=(a+i)%(a-j);
    }else{
        rec+=(n-i)%(n-i);
        sum--;
    }
}
cout<<rec+sum<<endl;
return 0;
}
