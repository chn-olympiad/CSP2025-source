#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+10]={0};
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int xr=a[1];
	int q=-1;
	int num=n*m;
	for(int j=0;j<num;j++){
		for(int i=1;i<=num-j;i++){
			if(a[i]<a[i+1]){
				q=a[i+1];
				a[i+1]=a[i];
				a[i]=q;
				q=0;
			}
		}
	}
	if(xr==a[num]){
		if(m%2==0){
			cout<<m<<" "<<1;
		}
		else{
			cout<<m<<" "<<n;
		}
		return 0;
	}

	int btd1=0;
	int l,h; 
	int sx=1;
	for(int i=1;i<=num;i++){
		if(a[i]!=xr){
			sx++;
		}
		else{
			if(sx%n==0){
				l=sx/n;
			}
			else{
				l=sx%n+sx/n;
			}
			btd1=sx%m;
			
			if(m%2==0){
				h=btd1;
			}
			else{
				h=m-btd1;
			}
			if(h==0){
				h=1;
			}
			cout<<h<<" "<<l;
			return 0;
		}
	}
	return 0;
}
