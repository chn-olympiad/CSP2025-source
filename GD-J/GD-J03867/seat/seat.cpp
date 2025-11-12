#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int num=a[1],l;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==num){
			l=n*m-i+1;
			break;
		}
	}
	cout<<l<<endl;
	int t;
	if((l%n)>0){
		t=l/n+1;
	}
	else{
		t=l/n;
	}
	cout<<t<<' ';
	if(t%2==0){
		if(l%n==0){
			cout<<1;
		}
		else
			cout<<n-(l%n)+1;
	}
	else if(t%2!=0){
		if(l%n==0){
			cout<<n;
		}
		else
			cout<<(l%n);
	}
	return 0;
}
