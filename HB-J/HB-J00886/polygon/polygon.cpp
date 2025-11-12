#include<bits/stdc++.h>
using namespace std;
long long n,a[1919810],s[1919810],s=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    s[1]=a[1];
    for(int i=2;i<=n;i++){
        s[i]=a[i]+a[i-1];
    }
    for(long long m=3;m<=n;m++){
        if(s[m]>a[m*2])s++;
    }cout<<s;
    fclose(stdin);
    fclose(stdout);
}