#include<bits/stdc++.h>
using namespace std;
int n,m,p;
struct tni{
	int id,v;
}a[105];
bool cmp(tni x,tni y){
	return x.v>y.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i].v;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;++i){
		if(a[i].id==1){
			p=i;
			break;
		}
	}
	if(p/n%2==1){
		if(p%n==0){
			cout<<p/n<<" "<<n;
			return 0;
		}
		else{
			cout<<p/n+1<<" "<<n-p%n+1;
			return 0;
		}
	}
	else{
		if(p%n==0){
			cout<<p/n<<" 1";
			return 0;
		}
		else{
			cout<<p/n+1<<" "<<p%n;
			return 0;
		}
	}
	return 0;
}
