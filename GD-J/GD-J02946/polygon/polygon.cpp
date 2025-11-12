#include <bits/stdc++.h>
using namespace std;
int a[5010];
int f(int x,int y){
	int l;
	while(y){
		l=x%2;
		x=x>>1;
		y--;
	}
	return l;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=pow(2,n)-1;i++){
		int cnt=0,maxn=-1;
		long long s=0;
		for(int j=1;j<=n;j++){
			if(f(i,j)){
				cnt++;
				s+=a[j];
				maxn=max(maxn,a[j]);
			}
		}
		if(cnt>=3&&s>2*maxn){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
