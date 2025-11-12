#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			cnt=i;
		}
	}
	c=cnt/n;
	r=cnt%n;
	if(r!=0) c++;
	if(r==0) r=n;
	if(c%2==0){
		r=n-r+1;
	}
	cout<<c<<" "<<r;
	return 0;
}