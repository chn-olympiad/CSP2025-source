#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=1e2+10;
int a[N];
int c,r;
int t;
bool cmp(int n1,int n2){
	return n1>n2;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1];
	int ans=n*m;
	sort(a+1,a+1+ans,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			t=i;
		}
	}
	
	r=(t-1)/n+1;
	if(t%n==0){
		if(r%2==0){
			c=r-1;
		}else{
			c=n;
			cout<<r<<" "<<c;
			return 0;
		}
	}
	if(r%2==0){
		c=n-t%n+1;
	}else{
		c=t%n;
	}
	cout<<r<<" "<<c;
return 0;
}
