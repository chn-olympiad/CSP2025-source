#include<bits/stdc++.h>
using namespace std;
struct Num{
	bool xxx[20];
	void clear(){
		for(int i=0;i<20;i++)xxx[i]=false;
		return ; 
	}
	Num operator+(const Num x)const{
		Num yyy;
		for(int i=0;i<20;i++)yyy.xxx[i]=xxx[i]^x.xxx[i];
		return yyy;
	}
	bool operator<(const Num x)const{
		for(int i=0;i<20;i++){
			if(xxx[i]==x.xxx[i])continue;
			return xxx[i]<x.xxx[i];
		}
		return false;
	}
};
map<Num,bool>mp;
map<Num,bool>empty_;
Num a[500005];
int real_num[25];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	Num real_k;
	real_k.clear();
	for(int i=0;k;i++){
		real_k.xxx[i]=bool(k&1);
		k>>=1;
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i].clear();
		for(int j=0;x;j++){
			a[i].xxx[j]=bool(x&1);
			x>>=1;
		}
	}
	int ans=0;
	Num now;
	now.clear();
	empty_[now]=true;
	mp=empty_;
	for(int i=1;i<=n;i++){
		now=now+a[i];
		if(mp[now+real_k]){
			++ans;
			mp=empty_;
			now.clear();
		}else{
			mp[now]=true;
		}
	}
	cout<<ans;
	return 0;
}
