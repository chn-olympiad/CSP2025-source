#include<bits/stdc++.h>
using namespace std;
int b[110];
int main(){
    int n,m;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>b[i];
    int x=b[0],l=m*n;
    sort(b,b+l);
    if(b[l]==x){
        cout<<1<<' '<<1;
        return 0;
    }
    else{
    	for(int c=1;c<=m;c++){
        	if(c%2==1){
            	for(int r=1;r<=n;r++){
            		if(b[c*r]==x&&b[c*r+1]<b[c*r]){
                    	printf("%d %d",c,r);
                    	return 0;
                	}
				}
        	}
        	else{
            	for(int r=n;r>0;r--){
            		if(b[c*r]==x&&b[c*r+1]<b[c*r]){
                    	printf("%d %d",c,r);
                    	return 0;
                	}
				}
        	}
    	}
	}
    return 0;
}

