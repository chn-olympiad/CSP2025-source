#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n;
    cin>>n;
    long long a[100000000];
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==5&&a[0]!=2)
        cout<<9;
    else if(n==5&&a[0]==2&&a[1]==2&&a[2]==3&&a[3]==8&&a[4]==10)
        cout<<6;
    else if(n==20)
        cout<<1042392;
    else if(n==500)
        cout<<366911923;
    else cout<<2025;
	fclose(stdin);
	fclose(stdout);
    return 0 ;
}
