#include <bits/stdc++.h>
using namespace std;
int n,m,e,r;
int a[105];
bool cmp(node x,node y){
	return x>y;
}
int main(){
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1],pm=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			pm=i;
		}
	}
	if(pm%n!=0){
		e=pm/n+1;
		if(e%2==1){
			r=pm%n;
		}
		else{
			r=n-(pm%n)+1;
		}
	}
		if(e%2==1){
			r=n;
		}
		else{
			r=1;
		}
		cout<<" "<<r;
	return 0;
}
