#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],cnt,ans,ans1,ans2;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>cnt;
	a[0]=cnt;
	for(int i=0;i<n*m-1;i++){
		cin>>a[i+1];
	}
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if (a[i]==cnt){
			ans=i+1;
			break;
		}
	}
	ans1=ans%n;
	ans2=(ans-1)/n+1;
	if (ans2 % 2==1){
		if (ans1==0){
			ans1=n;
		}
	}
	else{
		if (ans1==0){
			ans1=1;
		}
		else{
			ans1=n-ans1+1;
		}
	}
	cout<<ans2<<" "<<ans1;
	return 0;
}
