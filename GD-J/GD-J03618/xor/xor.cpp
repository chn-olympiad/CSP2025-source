#include<iostream>
using namespace std;
int n,x,a[500010],m;
void s(int l,int r){
	if(r>n){
		cout<<m;
		return;
	}int xx=a[l];
	for(int i=l+1;i<=r;i++)xx=xx^a[i];
	if(xx==x){
		m++;
		s(r+1,r+1);
	}else s(l,r+1);
}int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>x;
	for(int i=1;i<=n;i++)cin>>a[i];
	s(1,1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
