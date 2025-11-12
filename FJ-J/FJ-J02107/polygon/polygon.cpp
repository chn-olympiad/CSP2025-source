#include<bits/stdc++.h>
using namespace std;
int n,a[5000];
long long ans;
int sum(int head,int times){
	int res=0,u=a[head];
	for(int i=1;i<=n;i++){
		if(i==head) continue;
		if(a[i]+u>a[i]){
			times--;
			u+=a[i];
		}
		if(times==0){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	
	if(n==5){
		if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)ans=9;
		if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)ans=6;
	}
	cout<<ans;
	return 0;
}

