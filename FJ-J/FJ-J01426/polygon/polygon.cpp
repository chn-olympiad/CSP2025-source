#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n,cnt;
int a[100005];
struct m{
	int s,l;
}s[100005];
int f(int n,int k){
	int c=0;
	for(int i=0;i<pow(2,n);i++){
		int sum=0;
		for(int j=0;j<n;j++){
			sum+=a[j+1]*(i>>j&1);
		} 
		if(sum<k){
			c++;
		}
	}
	return c%998244353;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	for(int i=1;i<=n;i++){
		s[i].s=s[i-1].s+a[i];
		s[i].l=a[i];
		if(s[i].s<=s[i].l*2) continue;
		int p=s[i].s-s[i].l*2;
		cnt=(cnt+f(i-1,p))%998244353; 
	}
	cout<<cnt%998244353;
	return 0;
}

