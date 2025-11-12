#include<bits/stdc++.h>
using namespace std;
int a[105];
int b;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	b = a[1];
	sort(a+1,a+1+n*m,cmp);
	int temp = 0;
	for(int i = 1;i<=n*m;i++){
		if(b == a[i]){
			temp = i;
		}
	}
	int c = temp/n;
	int d = temp%n;
	if(d == 0){
		c = c-1;
		d = d+n;
	}
	int e = c+1,f;
	if(c%2 == 0){
		f = d;
	}else{
		f = n+1-d;
	}
	cout<<e<<" "<<f;
	return 0;
}

