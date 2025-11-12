#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
bool cmp(int x,int y){
	return x>y;
}
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,id,d,n1,m1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)  d=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==d)  id=i;
	}
	//cout<<id;
	n1=(id+n-1)/n;
	if(n1&1) m1=id-(n1-1)*n;
	else m1=n1*n-id+1;
	cout<<n1<<" "<<m1; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
