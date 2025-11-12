#include<bits/stdc++.h>
using namespace std;

long long n,m,a[105],max1=-10,s,b[105],k=1,a1,n1,m1;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    a1=a[1];
    for(int j=1;j<=m*n;j++){
        for(int i=1;i<=m*n;i++){
            if(max1<a[i])max1=a[i],s=i;
        }
        b[k]=max1;
        max1=-10;
        a[s]=-1;
        k++;
    }
    for(int i=1;i<=m*n;i++){
        if(a1==b[i])s=i;
    }
    if(s%n==0){
        m1=s/n;
        if(m1%2==0){
            n1=1;
        }else{
            n1=n;
        }
    }else{
        m1=(s/n)+1;
        if(m1%2==0){
            n1=(n-(s%n))+1;
        }else{
            n1=s%n;
        }
    }
    cout<<m1<<' '<<n1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
