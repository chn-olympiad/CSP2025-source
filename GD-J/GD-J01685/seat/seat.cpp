#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat","r",stdin);
	freopen("seat","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1000];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=0,a1=a[1];
	sort(a+1,a+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			t=i;
		}
	}
	int c;int r;
	c=t/n+1;
	t=t%n;
	if(c%2==0){
		r=n-t+1;
	}
	if(c%2==1){
		r=t;
	}
	cout<<c<<" "<<r;
	return 0;
}
