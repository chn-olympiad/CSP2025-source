#include<bits/stdc++.h>
#define MOD 998244353
#define L 5010
using namespace std;
int n,ans;
int a[L];
bool x[L];
//O(2^n)
void nxt(){
	x[0]=!x[0];
	int i=0;
	while(x[i]==0&&i<n){
		x[i+1]=!x[i+1];
		i++;
	}
}
bool isEnd(){
	for(int i=0;i<n;i++){
		if(!x[i])return false;
	}
	return true;
}
bool poly(){
	int sum=0;
	int maxn=-1;
	for(int i=0;i<n;i++){
		if(x[i]){
			maxn=max(maxn,a[i]);
			sum+=a[i];
		}
	}
	return sum>maxn*2;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(!isEnd()){
		nxt();
		if(poly())ans++;
	}
	cout<<ans%MOD;
	return 0; 
}
