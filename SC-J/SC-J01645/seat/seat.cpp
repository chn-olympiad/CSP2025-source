#include<bits/stdc++.h>
using namespace std;
long long re[101];
long long n,m;
long long xm;
bool amp(long long a,long long b){
	return a>b;
}
long long sw=1;
long long h,l;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=(n*m);i++) cin>>re[i];
	xm=re[1];
	sort(re+1,re+(n*m)+1,amp);
	while (xm!=re[sw]) sw++;
    l=sw/n;
	if (sw%n!=0) l++;
	if (l%2==0) h=(n-(sw%n)+1);
	else h=(sw%n);
	if (h==0) h=n;
	cout<<l<<' '<<h;
	return 0;
}