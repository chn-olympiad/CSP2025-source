#include<bits/stdc++.h>
using namespace std;
#define MAXN 500010
int n,k;
int a[MAXN];
bool flag[MAXN];
int solve1(){
	return n/2;	
}
int solve2(){
	for(int i=1;i<=n;i++) flag[i]=true;
	int ans=0;
	int i=1;
	while(i<=n){
		if(a[i]==k){
			ans++;
			cout<<i<<" "<<ans<<"\n";
		}
		else if(flag[i-1]&&i!=1&&a[i-1]==a[i]&&a[i-1]==(!k)){
			ans++;
			cout<<i-1<<" "<<i<<" "<<ans<<"\n";
			flag[i]=false;
		}
		i++;
	}
	return ans;
}
bool check(int h){
	int cnt=0;
	int i=1,sum=0;
	while(i<=n){
		sum^=a[i];
		if(a[i]==k){
			sum=0;
			cnt++;
		}
		if(sum==k){
			sum=0;
			cnt++;
		}
		sum^=a[i];
		i++;
	}
	return cnt>=h;
}
int solve3(){
	int ans=0;
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag1=true,flag2=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag1=false;
		if(a[i]>1) flag2=false;
	}
	if(flag1) cout<<solve1();
	else cout<<solve3();
	return 0;
}

