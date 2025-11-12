#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
bool pd(int x,int y){
	return x>y;
}
long long h=0,mod=998244353;
long long er[5005];
void s(long long sum,long long maxn,int x){
	if(x>n){
		return;
	}
	s(sum,maxn,x+1);
	if(maxn==0){
		s(sum+a[x],a[x],x+1);
	}else{
		if(sum+a[x]>maxn*2){
			h=(h+er[n-x])%mod;
			return;
		}
		s(sum+a[x],maxn,x+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	er[0]=1;
	for(int i=1;i<=5001;i++){
		er[i]=(er[i-1]*2)%mod;
	} 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,pd);
	s(0,0,1);
	cout<<h;
	return 0;
} 
