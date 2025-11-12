#include<bits/stdc++.h>
using namespace std;
int m,n,g=0,c=0,r,u=0;
int s[10000000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>s[i];
    }
    int e=s[0];
    for(int i=0;i<n*m;i++){
        if(s[i]>e)g++;
        if(s[i]<e)u++;
    }

    if(g<m){
        c=1;
        r=1+g;
    }else{
        c+=g/m+1;
        while(g>m){
            g-=m;
        }
        if(c%2==0)r=g;
        if(c%2!=0){
            if(g==m)r=m;
            if(g!=m)r=g+1;

        }
    }

    cout<<c<<' '<<r;
    return 0;

}
