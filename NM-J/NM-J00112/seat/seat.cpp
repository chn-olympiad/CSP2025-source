#include<bits/stdc++.h>
using namespace std;
main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int i,j,c,k,b[100],d,e;
    cin>>c>>k;
    for(i=0;i<c*k;i++){
        cin>>b[i];
    }
    d=1;
    e=b[0];
    for(i=0;i<c*k;i++){
        for(j=1;j<=i;j++){
            if(b[j]>b[j-1]){
            	if(b[i-1]==e){
        			d++;
   				}
    			if(b[i]==e){
        			d--;
    			}
                swap(b[j],b[j-1]);
            }
        }
    }
    if(d/c%2==0){
        d=k-d/c%2;
    }
    cout<<d/c+1<<' '<<d;
    return 0;
}
