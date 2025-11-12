#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	
	
	for(int i = 1;i<=n*m;i++){
		cin >> a[i];
	}
	int d=a[1],p;
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i<=n*m;i++){
		if(a[i]==d){
			p=i;
		}
	}
	int h=p%n,l=p/n;
	
	if(h==0){
		if(l%2==0) cout << l << " " << 1;
		else cout << l << " " << m;
	}
	else {
		l++;
		if(l%2==0) cout << l << " " << m-h+1;
		else cout << l << " " << h;
	}
	
	return 0;
}
