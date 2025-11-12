#include<bits/stdc++.h>
using namespace std;
long long q,a[123456],u=0,g=0;
void qaz(long long k,long long u,long long o){
	
	for(long long i=u;i<=q-k+1;i++)
	{
		if(k>1)qaz(k-1,i+1,o+a[i]);
		else if(o>a[i]){
			g++;
			g=g%998224353;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>q;
	for(long long i=1;i<=q;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+q);
	for(long long h=3;h<=q;h++)
	{
		qaz(h,1,0);
	}
	cout<<g;
	return 0;
}
