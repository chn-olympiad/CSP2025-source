#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
long long n,m,r,a[N],len;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	len=n*m;
	cin>>r,a[1]=r;
	for(int i=2;i<=len;i++)
		cin>>a[i];
	sort(a+1,a+len+1,cmp);
	int x;
	for(int i=1;i<=len;i++)
		if(a[i]==r) {x=i;break;}
	int i,j;
	if(x%m==0) i=x/m,j=n;
	else i=x/m+1,j=x%m;
	if(i%2==0) j=n-j+1;
	cout<<i<<' '<<j;
	return 0;
}
