#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=1;
	scanf("%d%d",&n,&m);
	int a[n*m+1];
	for(int i=0;i<n*m;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[0]){
			cnt++;
		}
	}
	int c=cnt/n;
	int r=cnt%n;
	if(c&1){
		if(r==0){
			r=n;
		}else{
			c++;
			r=n-r+1;
		}
	}else if(!(c&1)){
		if(r==0){
			r=1;
		}else{
			c++;
		}
	}
	cout<<c<<" "<<r<<endl; 
	return 0;
} 
