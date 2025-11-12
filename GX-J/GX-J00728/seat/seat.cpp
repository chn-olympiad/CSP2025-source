#include<bits/stdc++.h>;
using namespace std;
int n,m,d=0,r=0,c=0,i=0,k=0,u=1;
int a[]{0};
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    d=n*m;
    cin>>a[n*m];
    for(i;i<=d;i++){
        if(a[i]>=a[i+=1]){
            k=u;
        }
        else if(a[i]<a[i+=1]){
            u=i++;
            k=u;
        }
    }


    if(k%m==0){
        r=n;
        c=k/m;
        cout<<c<<" "<<r;
    }
     else if(k%m!=0){
        r=k%m;
        c=k/m+1;
        cout<<c<<" "<<r;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
