#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x,k,c,r;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    x=a[0];
    for(int i=0;i<n*m-1;i++){
        for(int j=0;j<n*m-1;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=0;i<n*m;i++){
        if(a[i]==x){
            k=i;
        }
    }
    c=k/n+1;
    if(c%2==1){
        r=1+k%n;
    }else{
        r=n-k%n;
    }
    cout<<c<<" "<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
