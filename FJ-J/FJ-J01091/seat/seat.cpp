#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],r;
bool cmp(int a1,int a2){
	return a1>a2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			r=i;
			break;
		}
//		cout<<a[i]<<" ";
	}
	int x,y;
	if(r%n==0){
		x=r/n;
		y=n;
	}else{
		x=r/n+1;
		if(x%2==0){
			y=n-(r%n)+1;
		}else{
			y=(r%n);
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
