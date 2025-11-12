#include <bits/stdc++.h>
using namespace std;
const int N=500;

int n,m;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
signed main ()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len=n*m;
	for (int i=1;i<=len;i++){
		cin>>a[i];
	}
	int r=a[1],k;
	sort(a+1,a+len+1,cmp);
	for (int i=1;i<=len;i++){
		if (a[i]==r) k=i; 
	} 
	int x;
	if (k%m==0){
		x=k/m;
		cout<<x<<" ";
	}
	else {
		x=k/m+1;
		cout<<x<<" ";
	}
	if (k%n==0&&x%2==1){
		cout<<n;
	}
	else if (k%n!=0&&x%2==1){
		int y=k%n;
		cout<<y;
	}
	if (k%n==0&&x%2==0){
		cout<<1;
	}
	else if (k%n==1&&x%2==0){
		cout<<(n+1)-(k%m);
	}
	return 0;
}
