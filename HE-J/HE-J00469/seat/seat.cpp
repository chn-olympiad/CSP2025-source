#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,z;
    cin>>n>>m;
    int s=n*m;
    int a[s];
    int b[s];
    for(int i=0;i<s;i++){
        cin>>a[i];
    }
    int q=a[0];
    for (int j=0;j<s;j++){
    for(int i=j;i<s;i++){
        if(a[i]<a[i+1]){
            z=a[i];
            a[i]=a[i+1];
            a[i+1]=z;
        }
    }}
    int f;
    for(int i=0;i<s;i++){
        if(a[i]==q) {
            f=i+1;
            break;
        }
    }

    int ansm= (f-1)/n+1,ansn;
    if(ansm%n==0){
        if(f%n==0) ansn=1;
        else ansn=n-(f%n)+1;
    }

    else {
        if(f%n==0){
            ansn=n;
        }
        else ansn=f%n;
    }

    cout<<ansm<<' '<<ansn;


    fclose(stdin);
    fclose(stdout);

    return 0;
}
