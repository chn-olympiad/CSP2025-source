#include<bits/stdc++.h>
using namespace std;int a[110];
bool cmp(int ab,int ac){
	return ab>ac;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}int b=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			b=i;
			break;
		}
	}
	int c=b/n+1;b%=n;
	if(b==0){
	b=n;
	c--;}cout<<c<<" ";
	if(c%2==1){
		cout<<b;
	}else{
		cout<<n-b+1;
	}
	return 0;
}
