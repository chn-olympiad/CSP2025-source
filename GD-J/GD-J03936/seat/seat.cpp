#include<bits/stdc++.h>
using namespace std;
int n,m,r,c,di;
struct stu{
	int v,id;
}a[105];
bool cmp(stu a,stu b){
	return a.v>b.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].v;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			di=i;
		}
	}
	if(di%n==0){
		r=di/n;
	}
	else{
		r=di/n+1;
	}
	if(r%2==0){
		if(di%n==0){
			c=1;
		}
		else{
			c=n-(di%n)+1;
		}
	}
	else{
		if(di%n==0){
			c=n;
		}
		else{
			c=di%n;
		}
	}
	cout<<r<<" "<<c;
	return 0;
} 
