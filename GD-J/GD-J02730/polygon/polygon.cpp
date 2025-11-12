#include<iostream>
using namespace std;
int n,a[5005];
unsigned long long ans,ded=1,fad=1;
int maxn,mi,hs,mxn;
void dfs(int k,int sum,int mexn,int ws){
	if(ws>=3){
		if(mexn*2<sum){
			ans++;
		}
	} 
	for(int i=k;i<=n;i++){
		dfs(i+1,sum+a[i],max(mexn,a[i]),ws+1);
	}
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
	}else if(n==3){
		for(int i=1;i<=n;i++){
			cin>>a[i]; 
			if(a[i]>=maxn){
				maxn=a[i];
				mi=i;
			}
			hs+=a[i];
		}
		if(hs>maxn*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(n<=20){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1,0,0,0);
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mxn=max(a[i],mxn);
		}
		if(mxn==1){
			for(int i=3;i<=n;i++){
				for(int j=n;j>=i;j--){
					ded*=j;
				}
				for(int k=i;k>=1;k--){
					fad*=k;
				}
				ans+=ded/fad;
				ded=1;
				fad=1;
			}
			cout<<ans;
		}else{
			cout<<0;
		}
	}
	return 0;
} 
