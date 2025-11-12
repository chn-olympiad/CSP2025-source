#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int m,n,a[105],cj,pm=0;
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    cj=a[1];
    sort(a+1,a+m*n);
    for(int i=m*n;i>=1;i--){
        for(int j=1;j<=m*n;j++){
            a[j]=a[i];
        }
    }
    for(int i=1;i<=m*n;i++){
        if(a[i]!=cj){
            pm++;
        }else{
            break;
        }
    }

    cout<<pm<<endl;
    int sum=1;
    while((pm-n)>0){
        pm-=n;
        sum++;
    }

    if(sum%2){
        cout<<sum-1<<" "<<pm-1;
    }else{
        cout<<sum<<" "<<n-pm+1;
    }
    return 0;
}
