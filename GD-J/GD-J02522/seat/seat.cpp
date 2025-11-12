#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int t=a[1];
	sort(a+1,a+1+n*m,cmp);
	int l=1,r=n*m,mid=(l+r)>>1;
	while(l+1<=r){
		mid=(l+r)>>1;
		if(a[mid]<t)
			r=mid-1;
		else
			if(a[mid]>t)
				l=mid+1;
			else{
				l=mid;
				break;
			}
				
	}
	int ans1,ans2;
	ans1=l/n;
	ans2=l%n;
	if(ans1<1){
		cout<<ans1<<' '<<ans2;
	}else{
		if(ans2>0)
			ans1++;
		if(ans2==0)
			if(ans1%2==0)
				ans2=1;
			else
				ans2=m;
		else
			if(ans1%2==0)
				ans2=m-ans2+1;
	}
	
	cout<<ans1<<' '<<ans2;
	fclose(stdin);
	fclose(stdout);
}
