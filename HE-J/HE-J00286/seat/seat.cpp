#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,c,r;
int a[105];
bool cmp(int x,int y){
	return x>y; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1],pm=1;
	sort(a+1,a+n*m+1,cmp);
	//for(int i=1;i<=n*m;i++) cout<<a[i]<<' ';
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			pm=i;
		}
	}
	//cout<<pm;
	if(pm%n!=0){
		c=pm/n+1;
		if(c%2==1){
			r=pm%n;
		}
		else{
			r=n-(pm%n)+1;
		}
	}
	else{
		c=pm/n;
		if(c%2==1){
			r=n;
		}
		else{
			r=1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
} 
