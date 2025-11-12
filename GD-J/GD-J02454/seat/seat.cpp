#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int q=0;
	cin>>n>>m;
	int a[10001];
	for(int i=1;i<=m+n;i++){
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+m+n+1,cmp);
	for(int i=1;i<=m+n;i++){
		if(a[i]==s) q+=i; 
	}
	int o=1;
	int y=q;
	int u=y;
	for(int i=1;i<=n+m;i++){
		if(y-n>=0){
			y-=n;
			o++;
		}		
	}
	int p=1;
	if(o%2!=0){
			for(int i=1;i<=n+m;i++){
			if(u-n>0){
			u-=n;	
		}
	}
	
		p+=u;			
	}
	else{
			for(int i=1;i<=n+m;i++){
		if(u-n>0){
			u-=n;
			
		}
	}

	p+=m-u;			
	}
	if(o!=n) o%=n;
	if(p!=m) p%=m;
	cout<<o<<' '<<p;
	return 0;
}
