#include<bits/stdc++.h>

using namespace std;
int a[10005],n,m,r,l;
int sum=0;
bool cmp(int x,int y) {
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	l=n*m;
	cin>>a[1];
	r=a[1];
	for(int i=2;i<=l;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+l,cmp);
	while(1) {
		sum++;
		if(a[sum]==r)
		break;
	}
	int x,y;
	if(sum%n==0) y=sum/n;
	else y=sum/n+1;
	int ans=0;
	int sum1=sum%n;
	if(sum1==0)	{
		if(y%2==1) x=n;
		else x=1;
		cout<<y<<" "<<x;
		return 0;
	}
	if(y%2==1) {
		for(int i=1;i<=n;i++) {
			ans++;
			if(ans==sum1) {
				x=i;
				break;
			}
		}
	}
	else {
		for(int i=n;i>=1;i--) {
			ans++;
			if(ans==sum1) {
				x=i;
				break;
			}
		}
	}	
	cout<<y<<" "<<x;
	return 0;
} 
