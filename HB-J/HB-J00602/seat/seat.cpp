#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    long long n,m;
    cin>>n>>m;
    long long x[n+100][m+100];
    long long a[n*m+100];
    int p;
    int q=0;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    p=a[1];
    for(int i=1;i<=n*m;i++)
        for(int j=1;j<=n*m;j++){
           if(a[j]<a[j+1]){
                q=a[j];
                a[j]=a[j+1];
                a[j+1]=q;
               q=0;
           }
        }
    //for(int i=1;i<=n;i++)
     //   for(int j=1;j<=m;j++){

    //}
    if(n==1){
        if(m==1)
            cout<<1<<" "<<1;
        if(m<=10){
            cout<<1<<" ";
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
