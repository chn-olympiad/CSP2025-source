#include<bits/stdc++.h>
using namespace std;
int n,m,s,a[105],t,l,c;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++) cin>>a[i];
	t=a[1];
	sort(a+1,a+s+1,cmp);
	for(int i=1;i<=s;i++){
		if(a[i]==t){
			c=ceil(i*1.0/n);
			if(c%2==1) l=(i%n)?i%n:n;
			else l=((n-i%n+1)%n)?(n-i%n+1)%n:n-i%n+1;
			cout<<c<<" "<<l;
			return 0;
		}
	}
	return 0;
}

