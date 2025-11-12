#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r;
	int n,m;
	int me,now;
	int linshi;
	int nx=1,mx=1,blx=1;
	int p[105];
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>p[i];
	}
	me=p[1];
	for(int i=1;i<m*n;i++){
		for(int j=i+1;j<m*n;j++){
			if(p[i]<p[j]){
				swap(p[i],p[j]);
			}
		}
	}
	for(int i=1;i<=m*n;i++){
		if(me==p[i]){
			now=i;
			break;
		}
	}
	if(now%n==0){
		r=now/n;
	} else{
		r=now/n+1;
	}
	linshi=r*n;
	if((linshi/n)%2 == 1){
		c=n;
		c=c-linshi+now;
	}
	else{
		c=1;
		c=c+linshi-now;
	}
	
	cout<<r<<" "<<c;
	
	
	return 0;
}
