#include<bits/stdc++.h>
using namespace std;
const int N=110;
struct OI{
	bool x;
	int p;
}a[N];
bool cmp(OI a,OI b){
	return a.p>b.p;
}
int main(){
	int n,m;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	std::cin>>n>>m;
	std::cin>>a[1].p;a[1].x=true;
	for(int i=2;i<=n*m;i++){
		cin>>a[i].p;a[i].x=false;
	}
	std::sort(a+1,a+n*m+1,cmp);
	int c,r,k;
	for(int i=1;i<=n*m;i++){
		if(a[i].x){
			k=i;
			break;
		}
	}
	c=k/n;
	if(k%n>0){
		c+=1;
	}

	r=k%n;
	if(r==0){
		r=n;
	}

	if(c%2){
		std::cout<<c<<' '<<r;
	}else{
		std::cout<<c<<' '<<m-r+1;
	}
	return 0;
}
