#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
bool cmp(int a1,int b1){
	return a1>b1;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R,temp=0;
	cin >> n >> m >> R;
	int t = n*m;
	a[0]=R;
	for(int i=1;i<t;i++){
		cin >> a[i];
	}
	sort(a,a+t,cmp);
	for(int i=0;i<t;i++){
		if(a[i]==R){
			temp=i+1;
			break;
		}
	}
	int rh=0,rl=0;
	if(temp%n==0){
		rl=temp/n;
	}
	else{
		rl=temp/n+1;
	}
	if(temp%n==0){
		rh=n;
	}
	else if(rl%2==1){
		rh=temp%n;
	}
	else{
		rh=(n+1)-temp%n;
	}
	cout<<rl << ' ' << rh;
	return 0;
}
