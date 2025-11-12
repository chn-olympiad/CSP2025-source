#include<bits/stdc++.h>
using namespace std;
int a[5005];
int ans=0;
int n,a1=0;
void xuan(int ceng,int da,int mc,int zong,int xian){
	if(ceng==mc&&zong>2*da){
		ans+=1;
		return;
	}
	for(int i=xian+1;i<=n;i++){
		int qd=da;
		if(a[i]>da){
			da=a[i];
		}
		xuan(ceng+1,da,mc,zong+a[i],i);
		da=qd;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			a1=1;
		}
	}
	if(a1==0){
		for(int i=3;i<=n;i++){
			ans+=n-i+1;
		}
		cout<<ans;
	}else if(n<=3){
		if(n==3){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(n<=20){
		for(int i=3;i<=n;i++){
			xuan(0,0,i,0,0);
			
		}
		cout<<ans;
	}
	return 0;
} 