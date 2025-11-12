#include<bits/stdc++.h>
using namespace std;
long long n,m,r,cc,a[2222222],xx,yy; 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r) cc=i;
	}
	xx=(cc-1)/n+1;
	if(xx%2==0){
		cc-=((xx-1)*n);
		cout<<xx<<" "<<n-cc+1;
	}
	else{
		cc-=((xx-1)*n);
		cout<<xx<<" "<<cc;
	}
	return 0;
} 
