#include<bits/stdc++.h>
using namespace std;
int a[1010];
int c[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int v=a[1];
	sort(a+1,a+n*m+1);
	
	int p;
	for(int i=1;i<=n*m;i++){
		if(a[i]==v){
			p=i;
			break;
		}
	}
	if(n==1){
		cout<<p<<" "<<1;
		return 0;
	}
	
	int x=1,y=1;
	bool f=0;
	p=n*m-p+1;
	while(p){
		p--;
		if(p==0){
			cout<<x<<" "<<y;
			break;
		}
		if(f==0)y++;
		else y--;
		if(y>n){
			f=!f;
			x++;
			y--;
		}else if(y<1){
			x++;
			y++;
			f=!f;
		}
	}
	return 0;
}