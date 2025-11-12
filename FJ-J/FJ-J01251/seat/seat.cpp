#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000];
int s;
int k;
int dq;
int h,l;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}

	 s=a[1];
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;i++){
		if(s==a[i]){
			dq=i;
		}
	}
	if(dq>=1&&dq<=n){
		cout<<1<<" "<<dq;
		return 0;
	}
	l=dq/m+1;
	int jo=dq/m+1;
	if(jo%2==0){
		h=n+1-(dq%m);
	}
	if(jo%2!=0){
		h=dq%m;
	}
	cout<<l<<" "<<h;
	return 0;
}
