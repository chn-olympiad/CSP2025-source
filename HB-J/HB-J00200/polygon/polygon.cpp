#include <bits/stdc++.h>
using namespace std;
int n;
int a[10000];
bool v[10000]={0};
int ans;
int sum=0;	     
int maxn=INT_MIN;
int pol(int x,int cur){
	if(cur==x&&sum>2*maxn){
		return 1;
	}
	else if(cur==x&&sum<=2*maxn){
		return 0;
	}
	for(int i=0;i<n;i++){
		if(!v[i]){
			v[i]=1;
			sum+=a[i];
			cur++;
			int maxs=maxn;
			maxn=max(a[i],maxn);
			return pol(x,cur);
			sum-=a[i];
			v[i]=0;
			cur--;
			maxn=maxs;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=0;i<n;i++){
		cin >>a[i];
	}
	for(int i=3;i<=n;i++){
		ans+=pol(i,0);
	}
	cout <<ans%998244353;
}
