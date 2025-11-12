#include<bits/stdc++.h>
using namespace std;
int n,a[5050],ans=0;
int maxn=-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			maxn=max(maxn,a[i]);
		}
		if(a[1]+a[2]+a[3]>2*maxn){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	if(n==4){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
			maxn=max(a[1],maxn);
			maxn=max(a[2],maxn);
			maxn=max(a[3],maxn);
		if(a[1]+a[2]+a[3]>2*maxn){
			
			ans++;
		}
			maxn=-1;
			maxn=max(a[1],maxn);
			maxn=max(a[2],maxn);
			maxn=max(a[4],maxn);
		if(a[1]+a[2]+a[4]>2*maxn){
			ans++;
		}
			maxn=-1;
			maxn=max(a[2],maxn);
			maxn=max(a[3],maxn);
			maxn=max(a[4],maxn);
		if(a[2]+a[3]+a[4]>2*maxn){
			ans++;
		}
			maxn=-1;
			maxn=max(a[1],maxn);
			maxn=max(a[2],maxn);
			maxn=max(a[3],maxn);
			maxn=max(a[4],maxn);
		if(a[1]+a[2]+a[3]+a[4]>2*maxn){
			ans++;
		}
		cout<<ans;
		return 0;
	}
	if(n==5){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
			maxn=max(a[1],maxn);
			maxn=max(a[2],maxn);
			maxn=max(a[3],maxn);
		if(a[1]+a[2]+a[3]>2*maxn){
			
			ans++;
		}
			maxn=-1;
			maxn=max(a[1],maxn);
			maxn=max(a[2],maxn);
			maxn=max(a[4],maxn);
		if(a[1]+a[2]+a[4]>2*maxn){
			ans++;
		}
			maxn=-1;
			maxn=max(a[2],maxn);
			maxn=max(a[3],maxn);
			maxn=max(a[4],maxn);
		if(a[2]+a[3]+a[4]>2*maxn){
			ans++;
		}
			maxn=-1;
			maxn=max(a[1],maxn);
			maxn=max(a[2],maxn);
			maxn=max(a[5],maxn);
		if(a[1]+a[2]+a[5]>2*maxn){
			
			ans++;
		}
			maxn=-1;
			maxn=max(a[2],maxn);
			maxn=max(a[3],maxn);
			maxn=max(a[5],maxn);
		if(a[2]+a[3]+a[5]>2*maxn){
			ans++;
		}
			maxn=-1;
			maxn=max(a[3],maxn);
			maxn=max(a[4],maxn);
			maxn=max(a[5],maxn);
		if(a[5]+a[3]+a[4]>2*maxn){
			ans++;
		}
		
		
			maxn=-1;
			maxn=max(a[1],maxn);
			maxn=max(a[2],maxn);
			maxn=max(a[3],maxn);
			maxn=max(a[5],maxn);
		if(a[1]+a[2]+a[3]+a[5]>2*maxn){
			ans++;
		}
		maxn=-1;
			maxn=max(a[4],maxn);
			maxn=max(a[2],maxn);
			maxn=max(a[3],maxn);
			maxn=max(a[5],maxn);
		if(a[4]+a[2]+a[3]+a[5]>2*maxn){
			ans++;
		}
			maxn=-1;
			maxn=max(a[1],maxn);
			maxn=max(a[2],maxn);
			maxn=max(a[3],maxn);
			maxn=max(a[4],maxn);
		if(a[1]+a[2]+a[3]+a[4]>2*maxn){
			ans++;
		}
			maxn=-1;
			maxn=max(a[1],maxn);
			maxn=max(a[2],maxn);
			maxn=max(a[3],maxn);
			maxn=max(a[5],maxn);
			maxn=max(a[4],maxn);
		if(a[1]+a[2]+a[3]+a[4]+a[5]>2*maxn){
			ans++;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
