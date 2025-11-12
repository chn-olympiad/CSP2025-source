#include<bits/stdc++.h>
using namespace std;

const int N=5005;
int n,a[N],psum[N];

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);	
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		psum[i]=psum[i-1]+a[i];
	}
	
	sort(a+1,a+1+n);
	
	if(n<=3){
		if(n<3) cout<<0;
		else{
			if(psum[n]>2*a[n]) cout<<1;
			else cout<<0;
		}
		return 0;
	}
	
	cout<<0;
	
	return 0;
}
