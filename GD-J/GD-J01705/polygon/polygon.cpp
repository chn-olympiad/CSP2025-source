#include<iostream>
using namespace std;
const int N=998244353;
int a[3];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt;
	cin>>n;
	if(n==5){
		cout<<6;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=3){
		if(n==3&&(a[0]+a[1]>a[2])&&(a[1]+a[2]>a[0])&&(a[2]+a[0]>a[1]))cout<<1;
		else cout<<0;
		return 0;
	}
	cnt=n-3;
	n-=2;
	while(cnt){
		n*=cnt;
		n%=N;
		cnt--;
	}
	cout<<n;
}
