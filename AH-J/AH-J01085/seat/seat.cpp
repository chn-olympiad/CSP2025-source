#include <bits/stdc++.h>
using namespace std;
long long n,m,tmpn,tmpm;
struct xx{
	long long s,id;
}a[1005];
bool cmp(xx a,xx b){
	return a.s>b.s;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	long long pos;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			pos=i;
			break;
		}
	}
	tmpm=ceil(pos*1.0/n);
	tmpn=pos%n;
	if(tmpn==0) tmpn=n;
	if(tmpm%2==0) tmpn=n-tmpn+1;
	cout<<tmpm<<" "<<tmpn;
	return 0;
}
