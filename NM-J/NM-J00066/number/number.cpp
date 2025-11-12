#include<bits/stdc++.h>
using namespace std;
int a[100000000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long s,n=1;
    cin>>s;
    while(s!=0){
        int tmp;
        tmp=s%10;
        a[n]=tmp;
        s=s/10;
        n++;
    }
    n=n-1;
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        cout<<a[i];
    }

    return 0;
}

