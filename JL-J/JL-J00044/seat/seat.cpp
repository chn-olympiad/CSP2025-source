#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int  main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int s[n][m],a[101],t;
    for(int i=0;i<=n*m;i++){
        cin>>a[i];
    }
    t=a[0];
    int c;
    for(int i=0;i<n*m;i++){
        for(int j=0;j<n*m-1;j++){
            if(i!=n*m){
                if(a[i]<a[i+1]){
                    c=a[i];
                    a[i]=a[i+1];
                    a[i+1]=c;
                }
            }
        }
    }
    int e=0,d=0;
    c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            s[e][d]=a[c];
            c++;
            if(i%2==0){
                d++;
            }
            else{
                d--;
            }
            if(d==n){
                e++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]==t){
                cout<<i<<" "<<j;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
