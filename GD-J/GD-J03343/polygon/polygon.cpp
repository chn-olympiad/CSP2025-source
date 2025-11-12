#include<bits/stdc++.h>
using namespace std;
int a[5010];
bool cmp(int x,int y){
	return x > y; 
}
int n;
long long ans;
void solve(int x,long long sum,long long more,int now,int c){
	int maxn=x;
	long long p=sum+more;
	//for(int i=1;i<=n;i++){
		if(p>2*maxn && c>=3){
			ans++;
			for(int l=1;l<=n-now;l++) ans+=l;
			ans%=998224353;
		}else{
			solve(maxn,p,a[now+1],now+1,c+1);
		}
		return;
	//}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		solve(a[i],0,a[i],i,1);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			//a[i]一定最大
//			for(int k=j+1;k<=n;k++){
//				if(a[k]+a[j]+a[i]>a[i]*2){
//					ans++;
//					for(int l=1;l<=n-k;l++) ans+=l;
//					ans%=998224353;
//				} 
//			} 
//		}
//	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
