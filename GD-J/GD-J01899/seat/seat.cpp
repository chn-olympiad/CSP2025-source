#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	int p=0;
	for(int i=1;i<=k;i++){
		cin>>a[i];
		if(i>1&&a[i]>a[1]){
			p++;
		}
	}
	p++;
	cout<<(p-1)/n+1<<' ';
	if(((p-1)/n+1)%2){
		cout<<(p-1)%n+1;
	}else{
		cout<<n-(p-1)%n;
	}
	return 0;
}
