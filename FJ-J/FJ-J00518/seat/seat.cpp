#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>a[i];
	s=a[0];
	sort(a,a+n*m,greater<int>());
	int c=1,r=0;
	bool b=1;
	for(int i=0;i<n*m;i++){
		if((r==m && b)||(r==1 && !b)){
			c++;
			b=(!b);
		}else{
			if(b) r++;
			else r--;
		}if(s==a[i]) break;
	}cout<<c<<" "<<r;
	return 0;
}
