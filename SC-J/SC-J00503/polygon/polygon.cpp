#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const ll Mod=998244353;
ll cnt;
ll pum(ll k){
	return 1<<k;
}
int main(){
//	IOS;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int* l=new int[n+5];
	for(int i=1;i<=n;++i){
		cin>>l[i];
	}
	sort(l+1,l+n+1);
	queue<int> f;
	ll sum,maxn;
	for(unsigned int num=1;num<=(1<<n);++num){
		while(!f.empty()){
			f.pop();
		}
		for(int i=0;i<=n;++i){
			if((num|pum(i))==num) f.push(l[i+1]);
		}
		if(f.size()<3) continue;
		maxn=2*f.back();
		sum=0;
		while(!f.empty()){
			sum+=f.front();
			f.pop();
		}
		if(sum>maxn){
			cnt++;
			cnt%=Mod;
		}
	}
	cout<<cnt%Mod; 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 