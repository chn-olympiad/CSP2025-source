#include <bits/stdc++.h>
using namespace std;
int n,m,s,a[1005],cnt=0,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
		s = a[1];
		if(a[i]>s) cnt++; 
	}
	s = cnt+1;//µÚ¼¸¸ö 
	c = ceil(1.0*s/n);
	if(c%2==0){
		r = n*c+1-s;
	}
	else{
		if(s%n==0) r = n;
		else r = s%n;
	} 
	cout << c <<" "<<r;
	return 0;
}
