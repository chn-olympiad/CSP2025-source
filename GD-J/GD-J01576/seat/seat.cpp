#include <bits/stdc++.h>
using namespace std;
int a[10010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int x=n*m;
	for(int i=1;i<=x;++i){
		cin >> a[i];
	}
	int y=a[1];
	sort(a+1,a+1+x,cmp);
	int id;
	for(int i=1;i<=x;++i){
		if(a[i]==y){
			id=i;
		}
	}
	cout << (id+n-1)/n << ' ';
	int b=id%(2*n);
	if(b==0){
		b=2*n;
	}
	if(b<=m){
		cout << b;
	}
	else{
		cout << n+1-b+n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
