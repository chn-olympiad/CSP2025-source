#include<bits/stdc++.h>
using namespace std;

int a[101],px[101];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int rfen=a[1];
	for(int j=1;j<=n*m;j++){
		int bmax=0,bmaxwei;
		for(int i=1;i<=n*m;i++){
			if(a[i]>bmax){
				bmax=a[i];
				bmaxwei=i;
			}
		}
		px[j]=bmax;
		a[bmaxwei]=-1;
		if(bmax==rfen)break;
	}
	int rming;
	for(int i=1;i<=n*m;i++){
		if(px[i]==rfen){
			rming=i;
			break;
		}
	}
	int ruwei=rming/(2*n);
	int rv=rming%(2*n);
	int c,r;
	if(ruwei==0){
		if(rv<=n){
			c=1;
			r=rv;
		}
		else{
			c=2;
			r=2*n-rv+1;
		}
	}
	else{
		if(rv==0){
			c=ruwei*2;
			r=1;
		}
		else{
			if(rv<=n){
				c=ruwei*2+1;
				r=rv;
			}
			else{
				c=ruwei*2+2;
				r=2*n-rv+1;
			}
		}
	}
	cout<<c<<' '<<r;
	
	fclose(stdin);
	fclose(stdout);
}
