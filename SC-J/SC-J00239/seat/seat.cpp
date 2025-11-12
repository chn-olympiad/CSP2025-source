# include <bits/stdc++.h>
using namespace std;
int n,m,cnt,col,l;
int a,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	cnt=1;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>=r){
			cnt++;
		}
	}
	col=(cnt+(n-1))/n;
	l=cnt-(col-1)*n;
	if(col%2==0){
		l=n-l+1;
	}
	cout<<col<<" "<<l;
	return 0;
} 