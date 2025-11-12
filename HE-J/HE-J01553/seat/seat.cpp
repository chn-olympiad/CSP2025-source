#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[10][10],d[100]={0},n,m,c,p,g=0;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>d[i];
    }
    p=d[0];
    for(int i=0;i<n*m;i++){
        for(int b=0;b<n*m-1;b++){
            if(d[b]<d[b+1]){
                c=d[b];
                d[b]=d[b+1];
                d[b+1]=c;
            }
        }
    }
    for(int b=0;b<m;b++){
        if(b%2==0){
           for(int c=0;c<n;c++){
              a[c][b]=d[g];
              g++;

           }
        }
        if(b%2==1){
            for(int c=n-1;c>=0;c--){
                a[c][b]=d[g];
                g++;

            }
        }
    }
    for(int b=0;b<m;b++){
        for(int c=0;c<n;c++){
              if(p==a[c][b]){
                 cout<<b+1<<" "<<c+1;
              }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
