#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int n,m,xr,cnt,a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xr=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xr){
			cnt=i;
			break;
		}
	}
	if(cnt%n==0){
		if((cnt/n)%2==0)
			cout<<cnt/n<<' '<<1;
		else
			cout<<cnt/n<<' '<<n;
	}else{
		if((cnt/n+1)%2==0)
			cout<<cnt/n+1<<' '<<n-cnt%n+1;
		else
			cout<<cnt/n+1<<' '<<cnt%n;
	}
	return 0;
}