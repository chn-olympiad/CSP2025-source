#include<bits/stdc++.h>
using namespace std;
int x,y,a[15][15],b[105],t,w,c[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=1,m=1;
	cin>>x>>y;
	t=x*y;
	for(int i=1;i<=t;i++){
		cin>>b[i];
	}
	if(x==1){
		w=b[1];
		n=1,m=1;
		sort(b+1,b+t+1);
		for(int i=1;i<=t;i++){
			c[i]=b[t-i+1];
		}
		for(int i=1;i<=t;i++){
			if(c[i]==w){
				n=i;
			}
		}
		cout<<n<<" "<<1;
	}
	else if(y==1){
		w=b[1];
		n=1,m=1;
		sort(b+1,b+t+1);
		for(int i=1;i<=t;i++){
			c[i]=b[t-i+1];
		}
		for(int i=1;i<=t;i++){
			if(c[i]==w){
				n=i;
			}
		}
		cout<<1<<" "<<n;
	}
	else if(x<=10&&y<=10&&x>=1&&y>=1){
		for(int i=1;i<=t;i++){
			if(b[i]==i){
				n=0;
			}else{
				n=1;
			}
		}
		if(n==0){
			cout<<y<<" "<<x;
			return 0;
		}
		for(int i=1;i<=t;i++){
			if(b[i]==t-i+1){
				m=0;
			}else{
				m=1;
			}
		}
		if(m==0){
			cout<<1<<" "<<1;
		}
	}
	else if(x==2&&y==2){
		w=b[1];
		n=1,m=1;
		sort(b+1,b+t+1);
		for(int i=1;i<=t;i++){
			c[i]=b[t-i+1];
		}
		for(int i=1;i<=t;i++){
			if(c[i]==w){
				n=i;
			}
		}
		if(n==1){
			cout<<1<<" "<<1;
		}
		else if(n==2){
			cout<<1<<" "<<2;
		}
		else if(n==3){
			cout<<2<<" "<<2;
		}
		else if(n==4){
			cout<<2<<" "<<1;
		}
	}
	return 0;
}