#include <bits/stdc++.h>
using namespace std;
int n,u;
long long a[100010],k;
long long xxor(long long x,long long y){
	string sx=to_string(x),sy=to_string(y),s;
	int pp=max(sx.size(),sy.size());
	for(int i=0;i<pp;i++){
		if(sx==sy)s+='0';
		else s+='1';
	}
	long long t=0;
	pp=s.size();
	for(int i=0;i<pp;i++)t+=pow(2,i)*int(s[i]-'0');
	return t;
}
void dfs(int p,int t){
	if(p==n){
		u=max(u,t);
		return;
	}
	long long l=a[p];
	if(l==k)dfs(p+1,t+1);
	for(int i=p+1;i<n;i++){
		l=xxor(l,a[i]);
		if(l==k)dfs(i+1,t+1);
	}
	dfs(p+1,t);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	if(k<2){
		bool f=1;
		for(int i=0;i<n;i++){
			if(a[i]>2){
				f=0;
				break;
			}else if(a[i]==k)u++;
		}
		if(f){
			cout<<u;
			return 0;
		}
	}
	dfs(0,0);
	cout<<u;
	return 0;
}
