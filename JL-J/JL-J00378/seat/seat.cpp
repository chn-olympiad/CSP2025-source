#include<bits/stdc++.h>
using namespace std;
bool cmp (int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int num=a[0];
    sort(a,a+n*m,cmp);
    int ans;
    for(int i=0;i<n*m;i++)if(a[i]==num)ans=i+1;
    int lie=(ans-1)/m+1,hang;
    if(lie&1){
        hang=ans%n;if(hang==0)hang=n;
    }
    else {
        hang=n+1-(ans%n);
    }
    cout<<lie<<" "<<hang;
    return 0;
}
//21min
