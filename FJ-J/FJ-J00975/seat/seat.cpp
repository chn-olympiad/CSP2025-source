#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen(luogu uid 546348
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a1[105],a[105];
	for(int i=1;i<=n*m;i++){
		cin>>a1[i];
	}
	int a2=a1[1];
	sort(a1+1,a1+1+(n*m));
	for(int i=1;i<=n*m;i++){
		a[i]=a1[(n*m)-i+1];
	}
	int i1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==a2){
			i1=i;
			break;
		}
	}
	int m1,n1;
	if(i1%n==0) {
		m1=i1/n;
		if(m1%2==1) n1=n;
		if(m1%2==0) n1=1;
		cout<<m1<<" "<<n1<<endl;
	}
	else {
		m1=i1/n+1;
		n1=i1%n;
		if(m1%2==0) n1=n-n1+1;
		cout<<m1<<" "<<n1<<endl;
	}
	return 0;
}

