#include<bits/stdc++.h>
using namespace std;
int m,n,s;
int a[111111];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>m>>n;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int a1=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=i;j<=n*m;j++){
            if(a[j]>a[i])swap(a[j],a[i]);
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==a1){
            s=i;
            break;
        }
    }
    int c,r;
    if(s%n==0){
        c=s/n;
    }else{
        c=s/n+1;
    }
    if(s%n==0||s%n==1){
        if((s/n)%2==0){
            r=1;
        }else{
            r=n;
        }
    }else{
        if((s/n)%2==0){
            r=s%n;
        }else{
            r=n-(s%n-1);
        }
    }
    cout<<c<<" "<<r<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
