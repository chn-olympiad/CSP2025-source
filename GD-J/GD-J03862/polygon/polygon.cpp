#include<bits/stdc++.h>
using namespace std;
int n,a[5010]={};
long long ans=0,p=998244353;
bool cmp(int pre,int nxt){
	return pre<nxt;
}
void f(int r,int t,int s,int dqs){
	if(t==a[r]&&dqs==r-1)return;
	if(t>=a[r]){
		long long cc=(r-dqs-1)*(r-dqs)/2;
		if(s>1&&t>a[r])ans++;
		ans+=cc;ans%p;
		return;
	}
	for(int i=dqs+1;i<r;i++){
		f(r,t+a[i],s+1,i);ans%=p;
	}
}
int main(){
//  	freopen("polygon.in","r",stdin);
//  	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=3;i<=n;i++){
		f(i,0,0,0);ans%=p;
	}
	cout<<ans;
	return 0;
}

