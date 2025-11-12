#include<bits/stdc++.h>
#define I ios::sync_with_stdio(0);
#define AK cin.tie(0);
#define CSP cout.tie(0);
using namespace std;
int n,m;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int k;int l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	I AK CSP
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			l=i;
			break;
		}
	}
	int x=ceil(l*1.0/n);
	l-=n*(x-1);
	int y;
	if(x%2==0) y=n-l+1;
	else y=l;
	cout<<x<<' '<<y;
	return 0;
}