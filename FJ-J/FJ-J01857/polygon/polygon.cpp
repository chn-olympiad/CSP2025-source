#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],cnt;
void dfs(long long num,int ii,long long maxn,bool beg){
	//cout <<num<<" "<<ii<<" "<<maxn<<"\n";
	cnt%=998244353;
	if(num>maxn*2){
		int s=n-ii+1;
		//cout<<"+"<<1+pow(2,s)-1<<"\n";
		cnt++;
		cnt+=pow(2,s)-1;
		return;
	}
	if(ii==n+1){
		return;
	}
	for(int i=ii;i<=n;i++){
		if(beg==0)	maxn=a[i];
		num+=a[i];
		dfs(num,i+1,maxn,1);
		num-=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	dfs(0,1,0,0);
	cout <<cnt;
	return 0;
} 
