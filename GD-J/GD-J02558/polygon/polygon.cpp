#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,a[N],sum,b[N];
bool used[N];
void oi(long long x,long long cnt,long long maxx,long long t){
	if(x==0){
		if(cnt>maxx*2){
		 	sum=(sum+1)%998244353;//cout<<cnt<<" "<<maxx<<endl;//
		}
		return;
	}
	for(int i=t;i<=n;i++){
		if(!used[i]){
			used[i]=true;
			oi(x-1,cnt+a[i],max(maxx,a[i]),t+1);
			used[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=3;i<=n;i++){
		oi(i,0,-1,1);
		for(int j=i;j>=2;j--) sum/=j;
	}
	cout<<sum;
	return 0;
} 
