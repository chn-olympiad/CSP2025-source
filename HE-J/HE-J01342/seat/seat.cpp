#include<bits/stdc++.h>
using namespace std;
int n,m,r,nm[101];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>nm[i];
	}
	r=nm[1];
	sort(nm+1,nm+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(r==nm[i]){
			r=i;
			break;
		}
	}
	int a,b,c=1;
	c=r/n;
	if(r%n!=0){
		c++;
	}
	cout<<c<<' ';
	a=r-(c-1)*n;
	if(c%2==1){
		if(a==0){
			cout<<n;
		}else{
			cout<<a;
		}
		
	}else{
		if(a==0){
			cout<<1;
		}else{
			cout<<n-a+1;
		}
		
	}
	
//	cout<<r;
}
