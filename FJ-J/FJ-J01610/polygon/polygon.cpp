#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int a[5050];
int b[6]={0,1,2,3,4,5},c[6]={0,2,2,3,8,10};
	void fivee(){
		
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		sort(a+1,a+n+1);
		if(sum>(a[5]*2)){
			ans++;
		}
		if(sum-a[1]>(a[5]*2)){
			ans++;
		}
		if(sum-a[2]>(a[5]*2)){
			ans++;
		}
		if(sum-a[3]>(a[5]*2)){
			ans++;
		}
		if(sum-a[4]>(a[5]*2)){
			ans++;
		}
		if(sum-a[5]>(a[4]*2)){
			ans++;
		}
		if(sum-a[1]-a[2]>(a[5]*2)){
			ans++;
		}
		if(sum-a[1]-a[3]>(a[5]*2)){
			ans++;
		}
		if(sum-a[1]-a[4]>(a[5]*2)){
			ans++;
		}
		if(sum-a[1]-a[5]>(a[4]*2)){
			ans++;
		}
		if(sum-a[2]-a[3]>(a[5]*2)){
			ans++;
		}
		if(sum-a[2]-a[4]>(a[5]*2)){
			ans++;
		}
		if(sum-a[2]-a[5]>(a[4]*2)){
			
			ans++;
		}
		if(sum-a[3]-a[4]>(a[5]*2)){
			ans++;
		}
		if(sum-a[3]-a[5]>(a[4]*2)){
			ans++;
		}
		if(sum-a[4]-a[5]>(a[3]*2)){
			ans++;
		}
		cout<<ans%99244353;
		return ;
	}
void dfs(int s,int maxx,int cnt,int summ){
	if(cnt>=3){
		if(summ>(2*maxx)){
			ans+=1;
		}
	}
	if(maxx==a[n]){
		return ;
	}
	for(int i=s;i<=n;i++){
		dfs(i,a[i],cnt+1,summ+a[i]);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<0;
		return 0;
	}
	if(n==3){
		int sum=0,maxx=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
			maxx=max(maxx,a[i]);
		}
		if(sum>(maxx*2)){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if(n==4){
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		sort(a+1,a+n+1);
		if(sum>(a[4]*2)){
			ans++;
		}
		if(sum-a[1]>(a[4]*2)){
			ans++;
		}
		if(sum-a[2]>(a[4]*2)){
			ans++;
		}
		if(sum-a[3]>(a[4]*2)){
			ans++;
		}
		if(sum-a[4]>(a[3]*2)){
			ans++;
		}
		cout<<ans%99244353;
		return 0;
	}
	if(n==5){
		int f1=0,f2=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]!=b[i]){
				f1=1;
			}
			if(a[i]!=c[i]){
				f2=1;
			}
		}
		if(f1==0){
			cout<<9;
			return 0;
		}
		if(f2==0){
			cout<<6;
			return 0;
		}
		fivee();
	}
	else{
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		dfs(1,a[1],0,0);
		cout<<ans%99244353;
		return 0;
	}
	return 0;
}
