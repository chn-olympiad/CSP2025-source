#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,d;
	long long a[100100],as=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	d=a[1];
	sort(a+1,a+1+n*m,cmp);
	long long x=1,y=1,way=1;
	while(1){
		if(a[as]==d){
			cout<<y<<' '<<x;
			return 0;
		}
		if(x+way>n and way==1){
			y++;
			way=-1;
		}
		else if(x+way==0 and way==-1){
			y++;
			way=1;
		}
		else{
			x+=way;
		}
		as++;
	}
	return 0;
}