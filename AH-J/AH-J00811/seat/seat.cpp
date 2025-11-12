#include<bits/stdc++.h>
using namespace std;
int n,m,s,ww,nm;
int a[200];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	ww=a[1];
	nm=n*m;
	for(int i=2;i<=nm;i++){
		cin>>a[i];
	}
	sort(a+1,a+nm+1,cmp);
	for(int i=1;i<=nm;i++){
		if(a[i]==ww){
			s=i;
			break;
		}
	}
	int l=(s+n-1)/n;
	int lm=s%n;
	if(s/n*n==s){
		lm+=n;
	}
	cout<<l<<" ";
	if(l%2==0){
		cout<<n-lm+1<<endl;
	}
	else if(l%2==1){
		cout<<lm<<endl;
	}
	return 0;
}
