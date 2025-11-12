#include<bits/stdc++.h>
using namespace std;
short n,m,a[200],p;
bool cmp(short x,short y){
	return x>y;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			p=a[i];
		}
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			p=i;
			break;
		}
	}
	if(p%n==0){
		if(p%(2*n)==0){
			cout<<2*(p/(2*n))<<' '<<1<<'\n';
		}else{
			cout<<2*(p/(2*n))+1<<' '<<n<<'\n';
		}
	}else{
		if((p/n)%2==0){
			cout<<p/n+1<<' '<<p%n<<'\n';
		}else{
			cout<<p/n+1<<' '<<n+1-p%n<<'\n';
		}
	}
fclose(stdin);
fclose(stdout);
	return 0;
}
