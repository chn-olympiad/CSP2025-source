#include <bits/stdc++.h>
using namespace std;
long long a[300];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,oi,h=1,l=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	oi=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==oi){
			oi=i;
			break;
		}
	}
	l+=oi/(2*n)*2;
	oi%=(2*n);
	if(oi>n){
		oi-=n;
		l++;
		h+=n-oi;
	}
	else{
		h=oi;
	}
	cout<<l<<" "<<h<<endl;
	return 0;
}
