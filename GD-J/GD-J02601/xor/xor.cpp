#include<bits/stdc++.h>
using namespace std;
int a[500010];
vector<int>v[500010];
int res=0;
int n,k;
void f(int now,int cnt){
	res=max(res,cnt);
	if(now==n){
		return;
	}
	for(auto x:v[now]){
		f(x,cnt+1);
	}
	f(now+1,cnt);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt=0;
	int mx=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt++;
		}
		mx=max(mx,a[i]);
	}
	if(mx<=k){
		cout<<cnt;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int sum=0;
			for(int l=i;l<j;l++){
				sum^=a[l];
			}
			if(sum==k){
				v[i].push_back(j);
			}
		}
	}
	f(0,0);
	cout<<res;
	return 0;
} 
