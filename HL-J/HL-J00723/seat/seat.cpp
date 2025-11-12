#include<bits/stdc++.h>
using namespace std;
bool f(int a,int b){
	return b<a;
}
int n,m,s1,s2,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		s1=a[1];
	}
	sort(a+1,a+n*m+1,f);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s1){
			s2=i;
		}
	}
	int nm1=s2/m,nm2=s2%m;
	if(nm2==0&&(nm1-1)%2==0){
		nm2=m;
		cout<<nm1<<' '<<nm2;
		return 0;
	}
	if(nm2==0&&nm1%2==0){
		nm1--;
		nm2=1;
		cout<<nm1<<' '<<nm2;
		return 0;
	}
	if(nm2!=0&&nm1%2==0){
		cout<<nm1+1<<' '<<nm2;
	}
	if(nm2!=0&&nm1%2!=0){
		cout<<nm1+1<<' '<<n+1-nm2;
	}
	return 0;
}
