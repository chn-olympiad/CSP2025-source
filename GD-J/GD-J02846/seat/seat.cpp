#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,ans1,ans2,k;
long long a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	sum=a[1];
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum){
			k=i;
			break;
		}
	}
	ans1=(k-1)/m+1;
	if(ans1%2==0){
		ans2=m+1-k+((ans1-1)*m);
	}
	if(ans1%2==1){
		if(k%m==0){
			ans2=ans1*m;
		}
		if(k%m!=0){
			ans2=sum%m;
		}
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
