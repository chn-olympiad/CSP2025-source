#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
bool v[5005],flag;
long long ans;
void dfs(int un,int num,int cnt,int maxn){
	if(num>=3&&cnt>2*maxn){
		ans++;
		return;
	}
	if(un==n&&cnt<=2*maxn){
		return;
	}
	for(int i=un;i<=n;i++){
		maxn=max(maxn,a[i]);
		if(v[i]==0){
			v[i]=1;
			dfs(i,num+1,cnt+a[i],maxn);
			v[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) flag=1;
	}
	if(n<3){
		cout<<"0";
		return 0;
	}
	if(n==3){
		int cnt=0,man=-1;
		for(int i=1;i<=n;i++){
			cnt+=a[i];
			man=max(man,a[i]);
		}
		if(cnt>2*man){
			cout<<"1";
			return 0;
		}
		else{
			cout<<"0";
			return 0;
		}
	}
	if(flag==0){
		for(int i=1;i<=n;i++){
			v[i]=1;
			dfs(i,1,a[i],a[i]);
			v[i]=0;
		}
		cout<<ans%998244353;
	}
	return 0;
}
