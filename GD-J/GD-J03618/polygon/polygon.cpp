#include<iostream>
using namespace std;
int n,a[5010],x;
void s(int l,int r){
	if(r>n){
		cout<<x%998244353;
		return;
	}int m1=0,m2=a[l];
	for(int i=l;i<=r;i++){
		m1+=a[i];
		m2=max(m2,a[i]);
	}m1*=2;
	if(m1>m2)x++;
	if(r<n)s(l,r+1);
	else s(l+1,l+3);
}int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	s(1,3);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
