#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],r,p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}r=a[1];
	sort(a+1,a+(n*m)+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			p=n*m-i+1;
			break;
		}
	}
	cout<<(p-1)/n+1<<' ';
	int o=p%n;
	if(o==0){
		o=n;
	}
	if(((p-1)/n+1)%2==0){
		cout<<n-(o)+1<<endl;
	}else{
		cout<<o<<endl;
	}
	return 0;
}

