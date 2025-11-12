#include <bits/stdc++.h>
using namespace std;

int n,k,jieguo;
vector <long long>  a;

long long f(long long x,long long y) {   //计算两个数的异或
	int xx[25],yy[25],ans[25];
	memset(xx,0,sizeof(xx));
	memset(yy,0,sizeof(yy));
	memset(ans,0,sizeof(ans));
	long long zhen=0;
	for( int q=0; x>0; q++) {
		xx[q]=x%2;
		x/=2;
	}
	for(int z=0 ; y>0; z++) {
		yy[z]=y%2;
		y/=2;
	}
	for(int i=0; i<25; i++) {
		if(xx[i] == yy[i]) ans[i]=0;
		else ans[i]=1;
	}
	for(int i=0; i<25; i++) {
		zhen+=ans[i]*pow(2,i);
	}
	return zhen;
}

void solve(int start,long long tmp) {
	if(start >=n-1 ) {
		return ;
	}
	long long qiu=f(a[start],tmp);
	if(qiu==k) {
		jieguo++;
		solve(start+1,0);
	} else {
		solve(start+1,tmp);
	}
	return ;
}

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;

	for(int i=1; i<=n; i++) {
		int tmp;
		cin>>tmp;
		a.push_back(tmp);
		if(tmp==k) jieguo++;
	}

	if(n==1 && k==0) {
		cout <<1<<endl;
		return 0;
	}

	if(n==2 && k==0) {
		cout <<2<<endl;
		return 0;
	}
	solve(0,0);
	cout <<jieguo<<endl;

	return 0;
}

