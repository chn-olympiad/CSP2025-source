#include<bits/stdc++.h>
using namespace std;

int n,m,c,r;
int a[102],x,xi; 

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		if(i==1){
			cin >> x;
			a[1]=x;
			continue;
		}
		cin >> a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			xi=i;
			break;
		}
	}
	if(xi%n!=0){
		c=xi/n+1;
		if(c%2==0){
			r=n-(xi%n)+1;
		}else{
			r=xi%n;
		}
	}else{
		c=xi/n;
		r=n;
	}
	cout << c << ' ' << r;
	return 0;
}
