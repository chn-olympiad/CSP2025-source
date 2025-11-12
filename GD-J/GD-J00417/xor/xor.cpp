#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,da[25],cnt,id[500005];
vector <int> ve;
void solve1(){
	cout<<n/2;
}
void solve2(){
	if(k==1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) sum++;
		}
		cout<<sum;
	}
	else {
		int sum=0;
		for(int i=1;i<=n;i++){
			if(!a[i]) sum++;
			else if(a[i+1]==1){
				i++;
				sum++;
			}
		}
		cout<<sum;
	}
}
int wei(int x){
	int w=0;
	while(x){
		w++;
		x>>=1;
	}
	return w;
}
void chai(int x,int idx){
	int w=wei(x);
	if(x==(1<<w-1)){
		ve.push_back(x);
		id[idx]=++cnt;
		return ;
	}
	for(int i=w-1;i>=0;i--){
		if(x&(1<<i)) ve.push_back(1<<i),cnt++;
	}
	id[idx]=cnt;
}
void solve3(){
	int sz=ve.size()-1;
	int w=wei(k);
	cout<<'\n';
	cnt=1;
	for(int i=w-1;i>=0;i--){
		if(k&(1<<i)) da[i]=1;
	}
	if(!k){
		for(int i=0;i<21;i++) da[i]=1;
	}
	for(int i=1;i<=sz;i++){
		int w=wei(ve[i]);
		if(i>=id[cnt+1]) cnt++;
		if(!da[w]){
//			if(id[cnt+1]==i+1) cnt++;
//			cout<<i<<' '<<cnt<<'\n';
			continue;
		}
		int sum=0,j=i;
		while(da[w]&&j<=sz){
			if(j!=i) w=wei(ve[j]);
			sum^=ve[j];
			cout<<j<<' '<<sum<<' '<<cnt<<'\n';
			j++;
			if(j>=id[cnt+1]) cnt++;
			if(sum==k){
				if(id[cnt+1]==j) ans++,cnt++/*,cout<<j<<' '<<cnt<<'\n'*/;
				sum=0;
			}
		}
		i=j-1;
	}
	cout<<ans;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	ve.push_back(0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		chai(a[i],i);
	}
//	for(int i=1;i<=n;i++) cout<<id[i]<<' ';
//	cout<<'\n';
//	for(auto it:ve) cout<<it<<' ';
//	cout<<'\n';
	if(n<=2) solve1();
	else if(n<=10) solve2();
	else if(n<=100){
		if(!k) solve1();
		else if(k<=1) solve2();
		else solve3();
	}
	else if(n<=2e5){
		if(k<=1) solve2();
		else solve3();
	}
	else solve3();
	return 0;
}
/*
9 0
4 7 2 1 1 2 1 2 4
*/
