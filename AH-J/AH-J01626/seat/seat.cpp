#include<bits/stdc++.h>
using namespace std;
long long a[105],n,m;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int q=a[1];
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a,a+n*m+1,cmp);
	long long ans1,ans2;
	for(int i=1;i<=n*m;i++){
		if(a[i]==q){
			if(i==1){
				ans1=1,ans2=1;
				break;
			}
			if(i%n==0){
				ans1=int(i/n);
			}else ans1=i%n+1;
			if(i%(2*n)==0)ans2=1;
			else if(i%(2*n)<=n)ans2=i%(2*n);
			else ans2=n-i%(2*n)+n+1;
			break;
		}
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
