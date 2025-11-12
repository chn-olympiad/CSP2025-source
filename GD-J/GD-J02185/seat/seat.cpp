#include <bits/stdc++.h>
using namespace std;
int n,m,a[207],s,t,x,y;
bool f;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;++i) cin>>a[i];
	t=a[1];
	sort(a+1,a+1+s,cmp);
	x=0,y=1;
	for(int i=1;i<=s;++i){
		if(f==0){
			++x;
			if(x>n){
				x=n;
				f=1;
				++y;
			}
		}else{
			--x;
			if(x<1){
				x=1;
				f=0;
				++y;
			}
		}
		if(a[i]==t) break;
	}
	cout<<y<<" "<<x;
	return 0;
}
