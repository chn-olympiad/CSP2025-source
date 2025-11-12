#include<bits/stdc++.h>
using namespace std;
int n,m,p;
int a[100001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==p){
			p=n*m-i+1;
			break;
		}
	}
	int li=(p+n-1)/n,ha=p%n;
	cout<<li<<" ";
	if(ha==0) ha=n;
	if(li%2==0){
		cout<<n-ha+1;
	}else{
		cout<<ha;
	}
	return 0;
}
