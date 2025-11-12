#include<bits/stdc++.h>
using namespace std;
int s[1000005];
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int a,n=0;
    cin>>a;
    while(a){
        s[n]=a%10;
        a=a/10;
        n++;
    }
    sort(1,n,n+s+1);
    for(int i=0;i<n;i++){
        cout<<s[i];
    }
    return 0;
}
