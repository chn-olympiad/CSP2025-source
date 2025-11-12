#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
struct st{
	int data;
	int x;
	int y;
	bool is_r;
}a[10005];
bool cmp(st n1 ,st n2){
	return n1.data>n2.data;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	a[1].is_r=true;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].data;
	}
	sort(a+1,a+n*m+1,cmp);
	
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
			    if(a[(i-1)*n+j].is_r){
				    cout<<i<<" "<<j;
			    }
		    }
	    }else{
	    	for(int j=n;j>=1;j--){
			    if(a[i*n-j+1].is_r){
				    cout<<i<<" "<<j;
			    }
		    }
		}
	}
	return 0;
} 
