#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int res,id=0;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	res=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==res){
			id=i;
			break;
		}
	}
	int d=id/(2*n),re=id%(2*n);
	int r=0,c=0;
	r=2*d+1;
	if(re>n){
		r++;
		re-=n;
		c=n-re+1;
	}else if(re==0){
		r--;
		c=1;
	}else{
		c=re;
	}
	cout<<r<<" "<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
