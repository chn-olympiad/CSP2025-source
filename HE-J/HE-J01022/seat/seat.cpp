#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	if(x>y){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[110],f=0,c=0,e=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	f=a[1];
	sort(a,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==f){
			f=i;
			break;
		}
	}
	c=f/m+1;
	if(c%2==0){
		e=m-f%m;
	}else{
		e=f%m+1;
	}
	cout<<c<<" "<<e;
	return 0;
}
