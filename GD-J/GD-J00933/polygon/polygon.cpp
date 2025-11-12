#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
long long a[N],n;
int dfs(long long t,long long cnt,long long ma,long long m){
	int sum=0;
	if(t>n){
		return 0;
	}
	for(int i=t;i<=n;i++){
		if(cnt+a[i]>max(ma,a[i])*2&&m>=3){
			sum++;
		}
		sum+=dfs(i+1,cnt+a[i],max(ma,a[i]),m+1);
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(1,0,-1,0);
	return 0;
} 
