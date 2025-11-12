#include <bits/stdc++.h>
using namespace std;
int  a[1001],t,cnt,b;

bool bijiao(int n, int m){
	return n>m;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c=0,r=0;
	cin >> n >> m;
	cin >> a[1];
	t=a[1];
	for(int i=2;i<=n*m;++i){
		cin >> a[i];
	}
	sort(a+1,a+1+n*m,bijiao);
	for(int i=1;i<=n*m;++i){
		cnt++;
		if(a[i]==t){
			break;
		}
	}
	if(cnt%n==0){
		c=cnt/n;
	}else{
		c=cnt/n+1;
	}
	if(cnt%(n*2)<=n&&cnt%(n*2)!=0){
		r=cnt%(n*2); 
	}else if(cnt%(n*2)==0){
		r=1;
	}else{
		r=n-cnt%n+1;
	}
	cout<< c << " " << r;
	return 0;
}
