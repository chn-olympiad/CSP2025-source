#include<bits/stdc++.h>
using namespace std;
int n,m,w,ans,c,r;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	w=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==w){
			ans=n*m-i+1;
			break;
		} 
	}
	c=(ans-1)/n+1;
	r=ans-n*(c-1);
	if(c%2==0){
		r=n-r+1;
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
