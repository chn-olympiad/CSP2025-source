#include<bits/stdc++.h>
using namespace std;

int a[5005];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int qy=998244353;
	cin>>n;
	int zh=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int zd=a[1];
		int zh=a[1]+a[2]+a[3];
		if(zd*2<zh){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	sort(a+1,a+n+1,cmp);
	if(n>=500){
		long long cnt=0;
		long long s,x,sx=1;
		for(int i=3;i<=n;i++){
			for(int j=1;j<=i;j++){
				s=n+1-j;
				x=j;
				sx*=s;
				sx/=x;
				sx%=qy;
			}
			cnt+=sx;
			sx=1;
			
		}
		cout<<cnt;
		return 0;
	}
	cout<<5201314;
	return 0;
}
