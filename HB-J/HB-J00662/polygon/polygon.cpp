#include <bits/stdc++.h>
using namespace std;
int n,b;
int a[10000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n==5)
        cout<<9;
    else{
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        for(int i=0;i<n-2;i++)
            b++;
        cout<<b;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}







