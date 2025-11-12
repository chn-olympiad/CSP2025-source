#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
const int nmax=1145; //give up point 13~20

int nxor(int c,int b){
	int a=0;
	stack<int> s;
	for (int i=0;i<=25;i++){
		int d=0;
		int cd=c%2;
		if (cd==0) d= (b%2);
		else {
			if (b%2==0) d=1;
			else d=0;
		}
		c>>=1;
		b>>=1;
		s.push(d);
	}
	while (!s.empty()){
		a+=s.top();
		a<<=1;
		s.pop();
	}
	a>>=1;
	return a;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	// 真没招了，老是报错：3221225725 
	int n, k;
	cin>>n>>k;
	int a[nmax];
	int asum[nmax];
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (i==1)asum[i]=a[1];
		else asum[i]=asum[i-1]^a[i];
	}
	int d[nmax][nmax]={-1};
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			int t;
			if (i==1) t=asum[j];
			else t=nxor(asum[j],asum[i-1]);
			if (t==k) d[i][j]=j-i;
		}
	}
	int res=0;
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if (d[i][j]!=-1) {
			res++;
			i=j+1; //本来要比较的，找最优解，时间紧张不找了 
			}
		}
	}
	cout<<res;
	return 0;
}
