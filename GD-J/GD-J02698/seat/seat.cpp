#include<bits/stdc++.h>
using namespace std;
int n,m,sum,ansx,ansy;
struct sru {
	int cj,hm;
}a[10005];
bool cmp(sru x,sru y)
{
	return x.cj>y.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].cj;
	a[1].hm=1;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].hm==1)
		{
			sum=i;
			break;
		}
	}
	if(sum%(2*n)<=n) ansy=sum%(2*n);
	else ansy=2*n-sum%(2*n)+1;
	ansx=ceil(sum*1.0/n);
	cout<<ansx<<" "<<ansy;
	return 0;
}
