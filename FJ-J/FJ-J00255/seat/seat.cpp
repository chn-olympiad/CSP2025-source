#include<bits/stdc++.h>
using namespace std;
int mp[11][11],n,m,x,p[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>p[i];
    }
    x=p[1]; 
    int s=1;
    sort(p+1,p+n*m+1,cmp);
    for(int i=1;i<=m;i++){
    	if(i%2==1){
    	    for(int j=1;j<=n;j++){
			    mp[j][i]=p[s];
				s+=1;
    	    }
    	}
    	else{
    		for(int j=n;j>=1;j--){
			    mp[j][i]=p[s];
				s+=1;
    	    }
		}
    }
    for(int i=1;i<=m;i++){
    	for(int j=1;j<=n;j++){
    		if(mp[j][i]==x){
    			cout<<i<<' '<<j;
			}
    	}
    }
	return 0;
}
