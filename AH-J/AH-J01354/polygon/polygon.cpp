#include<bits/stdc++.h>
using namespace std;
long long n,a[10010],p[10010],id,cnt;
bool print(){
	long long sum1=0,max1=INT_MIN;
	if(id<3) return false;
	for(int i=0;i<id;i++){
		sum1+=p[i];
		if(p[i]>max1){
			max1=p[i];
		}
	}
	if(sum1>max1*2){
		return true;
	}
	return false;
}
void dfs(long long x){
	p[id]=a[x],id++;
	if(print()){
		cnt++;
	}
	for(int i=1;i<n-x;i++){
		long long tx=x+i;
		if(tx<n){
			dfs(tx);
		}
	}
	id--;
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		id=0;
		dfs(i);
	}
	cout<<cnt%998244353;
	return 0;
}
