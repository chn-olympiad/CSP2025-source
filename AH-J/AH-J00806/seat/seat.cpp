#include<bits/stdc++.h>
using namespace std;
int a[10010];
int ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+1+n*m);
	ans=(lower_bound(a+1,a+1+n*m,t)-a);
	ans=n*m-ans+1;
	//cout<<"hehe "<<ans<<endl;
	int x,y;
	if(ans%m==0) x=ans/m;
	else x=ans/m+1;
	if(ans%m==0&&x%2==1) y=m;
	else if(ans%m==0&&x%2==0) y=1;
	else if(x%2==1) y=ans-ans/m*m;
	else y=(ans/m+1)*m-ans+1; 
	cout<<x<<" "<<y;
	return 0;
}
