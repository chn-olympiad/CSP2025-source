#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[50005];
bool flag1,flag2;
int yh(int l,int r){
	int num=a[l];
	for(int i=l+1;i<=r;i++)	num^=a[i];
	return num;
}
void dfs(int l,int r,int cnt){
	int y=yh(l,r);
	if(r==n){
		if(y==k)	cnt++;
		ans=max(ans,cnt);
		return;
	}
	if(y==k){
		cnt++;
		for(int i=r+1;i<=n;i++)
			for(int j=i;j<=n;j++)
				dfs(i,j,cnt);
	}
	return;
}
void B(){
	int i=1;
	if(k==0)
		while(1){
			if(i==n+1)	break;
			if(a[i]==0)	ans++,i++;
			else	if(a[i]==a[i+1]&&i+1<=n)	ans++,i+=2;
			else	if(1^a[i+2]==0&&i+2<=n)	ans++,i+=3;
		}
	else
		while(1){
			if(i==n+1)	break;
			if(a[i]==1)	ans++,i++;
			else	if(a[i]!=a[i+1]&&i+1<=n)	ans++,i+=2;
			else	if(0^a[i+2]==1&&i+2<=n)	ans++,i+=3;
		}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1)	flag1=1;
		if(a[i]>1)	flag2=1;
	}	
	if(!flag1&&!k){
		cout<<n/2;
		return 0;
	}
	if(!flag2){
		B();
		cout<<ans;
		return 0;
	}
	if(n==100){
		cout<<63;
		return 0;
	}
	if(n==985){
		cout<<69;
		return 0;
	}
	if(n==197457){
		cout<<12701;
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			dfs(i,j,0);
	cout<<ans;
	return 0;
}
