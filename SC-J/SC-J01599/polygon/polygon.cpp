#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
const int mod=998244353;
int n,num;
int a[5005];
void dfs(int now,int val,int nu,bool shouldplus){
	if(now==n+1){
		if(nu>=3){
			if(val>a[n]*2){
				if(shouldplus){
					num++;
				}
			}
		}
		return ;
	}
	if(nu>=3&&val<=a[now])return ;
	if(nu>=3&&shouldplus){
		num++,num=num%mod;
	}
	dfs(now+1,val+a[now],nu+1,1);
	dfs(now+1,val,nu,0);
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	fre("polygon");
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,1);
	cout<<num;
	return 0;
}