#include<bits/stdc++.h>
using namespace std;
int n,m,a[106],zj[106];
bool cmp(int x,int y){
	return x>y;
}
int js(int x){
	if(x!=0) return x;
	return 2*n;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cd=2*n;
	for(int i=1;i<=n;i++) zj[i]=i;
	for(int i=n+1,j=n;i<=cd;i++,j--) zj[i]=j;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int z=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++) 
		if(a[i]==z){
			cout<<(i-1)/n+1<<" "<<zj[js(i%cd)];
			break;
		}
	return 0;
}