#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a1,n,m,r=0,c=0,p=0,j,k,u=0;
    int a[101];
    cin>>n>>m>>a1;
    for(int i=1;i<n*m;i++){
        cin>>a[i];
    }
    for(int i=1;i<n*m;i++){
        if(p==0&&a1>a[i]){
            r++;
        }
        if(p==1&&a1>a[i]){
            r--;
        }
        if(p==0&&r==n){
            c++;
            p=1;
        }
        if(p==1&&r==n){
            c++;
            p=0;
        }

    }
    for(int i=1;i<n*m;i++){
        if(a1>a[i]){
            u=1;
        }
    }

    j=m-c;
    k=n-r;
    if(j==0)j==2;
    if(k==0)k==2;
    if(u==1){
        cout<<j<<" "<<k;

    }
    else{
        cout<<n<<" "<<m-1;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;

    }
