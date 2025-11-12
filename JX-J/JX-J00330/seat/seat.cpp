#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1],p;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			p=i;
			break;
		}
	}
	int l=p/n,h=p%n;
	if(h>0){
		l++;
		cout<<l<<" ";
		if(l%2==0) cout<<n-h+1;
		else cout<<h;
	}
	else if(h==0){
		cout<<l<<" ";
		if(l%2==0) cout<<1;
		else cout<<n;
	}
	return 0;
}

