#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int b[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,imp,xb;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		if(i==1) imp=b[i];
	}
	sort(b+1,b+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++) if(b[i]==imp) xb=i;
	int rn,rm;
	rm=xb/n;
	if(xb%n!=0) rm++;
	int yu;
	if(xb%n==0) yu=n;
	else yu=xb%n;
	if(rm%2==0) rn=n-yu+1;
	else rn=yu;
	cout<<rm<<" "<<rn;
	return 0;
}
