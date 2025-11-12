#include<bits/stdc++.h>
using namespace std;
struct seat{
	int p,x,y,pai;
};
bool cmp(seat a,seat b){
	return a.p>b.p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k=1;
	seat a[101];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].p;
		a[i].pai=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
			    a[k].x=i;
			    a[k].y=j;
			    if(a[k].pai==1){
			    	cout<<a[k].x<<' '<<a[k].y;
			    }
		    	k++;
		    }
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				a[k].x=i;
			    a[k].y=j;
			    if(a[k].pai==1){
			    	cout<<a[k].x<<' '<<a[k].y;
			    }
		    	k++;
		    }
	    }
	}
	return 0;
} 
