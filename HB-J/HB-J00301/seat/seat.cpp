#include<bits/stdc++.h>
using namespace std;
int m,n,k;
int a[11000];
int b[11][11];
int main(){

    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]>a[1]){
            k++;
        }
    }

    int x=k/n+1;
    int y;
    if(x%2==0){
         y=n-((k+1)%n);


            if(y==0){
            y=n;
        }


    }
    else{
        y=k%n;

        if(x==1&&y<=k){
            y=k+1;
         }


        else if(y==0){
            y=1;
        }
    }
    cout<<x<<" "<<y;
}
