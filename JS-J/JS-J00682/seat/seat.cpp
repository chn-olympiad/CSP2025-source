#include<bits/stdc++.h>
using namespace std;
int a[110000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	cin>>x;
	a[1]=x;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int xi=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==x) xi=i;
	}
	int p=xi/n,q=xi%n;
	if(q==0){
		if(p%2==1){
			cout<<p<<" "<<n;
		}
		else cout<<p<<" "<<1;
	}
	else{
		if(p%2==0) cout<<p+1<<" "<<q;
		else cout<<p+1<<" "<<n-q+1;
	}
	return 0;
}
