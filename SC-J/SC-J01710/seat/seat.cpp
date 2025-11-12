#include<bits/stdc++.h> 
using namespace std;
int a[105],n,m,b;
int c=1,r=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			cout<<c<<' '<<r;
			return 0;
		}
		
		if(c%2==1) r++;
		else r--;
		
	    if(r==m+1){
	    	r=m;
			c++;
		}else if(r==0){
			r=1;
			c++;
		}	
	}
	return 0;
	
}