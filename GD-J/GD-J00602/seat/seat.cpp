#include<bits/stdc++.h>
using namespace std;
int n,m,p,tx,ty;
int a[105]; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==x){
			p=n*m-i+1;
			break;
		}
	}
	if(p%n==0) ty=p/n;
	else ty=p/n+1;
	p=p-(ty-1)*n;
	if(ty%2==1){
		cout<<ty<<" "<<p;
	}
	else{
		cout<<ty<<" "<<n-p+1;
	} 
	return 0;
}
