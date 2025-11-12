#include<bits/stdc++.h>
using namespace std;
bool vis[500005]={0};
int a[500005],cnt=0,n,k;
void f(int l,int deep){
	if(deep>n){
		return;
	}
	int ans=a[l],sum=0,r=l-1+deep;
	if(vis[l]==1){
		r=l-n;
		ans=k-1;
	}
	
	for(int i=l+1;i<=r;i++){
		int nxor=a[i],nans=ans,now=0;
		if(vis[i]==1){
			r=l-n;
			ans=k-1;
			break;
		}
		while(1){
			if(nans%2!=nxor%2){
				sum+=1*pow(2,now);
				ans=sum;
			}
			else{
				if(nans%2==1){
					sum-=1*pow(2,now);
					ans=sum;
				}
			}
			now++;
			nans/=2;
			nxor/=2;
			if(nans==0&&nxor==0){
				break;
			}
		}
	}
	r=l-1+deep;
	
	if(ans==k){
		cnt++;
		
		for(int i=l;i<=r;i++){
			vis[i]=1;
		}
	}
	if(r>=n){
		f(1,deep+1);
	}
	else{
		f(l+1,deep);
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f(1,1);
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
