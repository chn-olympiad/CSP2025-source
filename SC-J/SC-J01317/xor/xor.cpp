#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,cnt,cnt1,cnt2;
int a[500005];
bool f[500005],ff,f2[500005];
bool isok(int s,int t){
	bool pd1=0;
	int ans=a[s];
	for(int i=s+1;i<=t;i++){
		ans^=a[i];
	}
	if(ans==k) pd1=1;
	for(int i=s;i<=t;i++){
		if(f[i]==1) return false;
	}
	if(pd1==1) return true;
	return false;
}
void czf(int l,int r){
	for(int i=l;i<=r;i++) f[i]=1;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt2++;
			f2[i]=1;
		} 
		if(a[i]!=1) ff=1;
	}
	if(k==0&&ff==0){
		cout<<n/2<<endl;
		return 0;
	}
	int l=1,r=1;
	while(l<=r&&r<=n){
		if(isok(l,r)){
			czf(l,r);
			cnt++;
			l=r+1;
			r=l;
		}
		else{
			r++;
		}
	}
	for(int i=1;i<=n;i++) f[i]=0;
	l=n,r=n;
	while(l<=r&&l>=1){
		if(isok(l,r)){
			czf(l,r);
			cnt1++;
			r=l-1;
			l=r;
		}
		else{
			l--;
		}
	}
	cout<<max(cnt2,max(cnt,cnt1))<<endl;
	return 0;
}