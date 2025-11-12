#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],r,I=1,J=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1],sort(a+1,a+1+n*m);
	for(int i=n*m;a[i]!=r;){
		while(I<n&&a[i]!=r) I++,i--;
		if(a[i]==r) break;		
		J++,i--;
		while(I>1&&a[i]!=r) I--,i--;
		if(a[i]==r) break;		
		J++,i--;
	}
	cout<<J<<" "<<I;
	return 0;
}
