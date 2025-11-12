#include<bits/stdc++.h>
using namespace std;
bool cmp(int r1,int r2){
	return r1>r2;
}
int y[1005][1005];
int a[100005];
int n,m;
int R;
int u=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	
	cin>>n>>m;
	
	if(n==1){//±£·ÖAB
		for(int i=1;i<=n*m;i++){
	 	    cin>>a[i];
	    }
	    R=a[1];

	    sort(a+1,a+(n*m)+1,cmp);
	    
	    for(int i=1;i<=n*m;i++){
	 	   if(a[i]==R){
	 	   	cout<<1<<" "<<i;
	 	   	return 0;
			}
	    }
	}
	
	else{
		
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	
	R=a[1];
	
	sort(a+1,a+(n*m)+1,cmp);
	
	for(int i=1;i<=n;i++){
		if(i%2!=0){
		    for(int j=1;j<=m;j++){
			    y[j][i]=a[u];
			    u++;
		    }
	    }else{
	
		for(int j=m;j>=1;j--){
			y[j][i]=a[u];
			u++;
		}
	}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(y[j][i]==R){
				cout<<i<<" "<<j;
			}
		}
	}
}
	

	return 0;
}
