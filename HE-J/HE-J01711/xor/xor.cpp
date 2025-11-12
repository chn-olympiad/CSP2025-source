#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
template<typename T>void read(T&x){
	int f=1;x=0;char c;
	do{c=getchar();if(c=='-')f=-1;}while(!isdigit(c));
	do{x=x*10+c-'0';c=getchar();}while(isdigit(c));x=x*f;
}
int n,k,a[N],ans,su,o,dp[N];
struct node{
	int a,b;
}x[N];
bool f1,f2;
bool cmp(node x,node y){
	return x.b>y.b;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	read(n);read(k);
	for(int i=1;i<=n;i++){
		read(a[i]);
		if(a[i]!=1)f1=1;
		if(a[i]!=1&&a[i]!=0)f2=1;
	}
	if(!f1){
		cout<<n;
		return 0;
	}
	if(!f2){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
				if(a[i]==1&&a[i+1]==1)ans++;
			}
			cout<<ans;
			return 0;
		}
		else {
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
			}
			cout<<ans;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			su=a[i];
			for(int k=i+1;k<=j;k++){
				su=su^a[k];
			}
//			if(i==1&&j==2)cout<<su<<'\n';
			if(su==k){
//				cout<<i<<" "<<j<<'\n';
				x[++o].a=i,x[o].b=j;dp[o]++;
			}
		}
	}
//	for(int i=1;i<=o;i++){
//		cout<<x[i].a<<" "<<x[i].b<<'\n';
//	}
	sort(x+1,x+1+o,cmp);//anyoubianjiepaixv
//	for(int i=1;i<=o;i++){
//		cout<<x[i].a<<" "<<x[i].b<<'\n';
//	}
	for(int i=1;i<=o;i++){
		for(int j=i+1;j<=o;j++){
//			cout<<x[j].b<<" "<<x[i].a<<'\n';
			if(x[j].b<x[i].a)dp[i]=max(dp[i],dp[j]+1);
//			cout<<i<<" "<<j<<" "<<dp[i]<<" "<<dp[j]<<" "<<x[i].a<<" "<<x[j].b<<'\n';		
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
