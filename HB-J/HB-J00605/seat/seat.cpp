#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[100],i,count,R,seat,m2;
    cin>>n>>m;
    for(i=0;i<n*m;i++){
        cin>>a[i];
    }
    R=a[0];
    for(count=0;count<=i;count++){
        int c;
        for(int x=count;x<=i;x++){
            if(a[x]>a[count]){
                c=a[count];
                a[count]=a[x];
                a[x]=c;
            }
        }
    }
   
    for(int j=0;j<=n*m;j++){
        if(a[j]==R) seat=j+1;
    }
    
    if(seat/n*n==seat) m2=seat/n;
    else if(seat/n<seat) m2=seat/n+1;
    
    if(m2%2!=0) {cout<<m2<<" "<<seat-n*(m2-1);return 0;}

    if(m2%2==0) {cout<<m2<<" "<<n*m2-seat+1;return 0;}
    
    
}