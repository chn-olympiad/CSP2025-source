#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x=1,p=1;
    cin>>n>>m;
    int a,b;
    for(int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if(i==1)
            {
                cin>>a;
            }
            else
            {
                cin>>b;
            }
            if(a<b){
                x++;
            }
        }
    }

    for(int j = 1;j<=n;j++){
        if(j%2==1){
            for(int i=n;i<=m;i++){

                if (p==x){
                    cout<<j<<' '<<i;
                }
                p++;
            }
        }
        else{
            for(int i=m;i>=1;i--)
            {

                if(p==x)
                {
                    cout<<j<<' '<<i;
                }
                p++;
            }
        }
    }
    return 0;
}
