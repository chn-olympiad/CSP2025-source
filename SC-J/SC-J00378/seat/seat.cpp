#include<bits/stdc++.h>
using namespace std;

const int N=105;
int n,m;
int a[N],ans,num;

void dfs(int l,int r){
	int mid=(l+r)/2;
	if(r<l){
		ans=l;
		return;
	}
	if(a[mid]<num){
		dfs(mid+1,r);
	}
	else{
		dfs(l,mid-1);
	}
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+1+n*m);
	dfs(1,n*m);
	ans=n*m-ans+1;
	int c,r;
	if(ans%n==0){
		c=ans/n;
		if(c%2==0){
			r=1;
		}
		else{
			r=n;
		}
	}
	else{
		c=ans/n+1;
		if(c%2==0){
			r=n-ans%n+1;
		}
		else{
			r=ans%n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}