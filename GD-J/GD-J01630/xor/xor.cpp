#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],maxr=0;
struct ad{
	long long l;
	long long r;
};
bool cmp(ad fuck,ad ccf){
	return fuck.l>ccf.l;
} 
ad b[500005];long long len=1;
long long dfs(long long ans,long long rr,long long ip){
	if(rr>=maxr||ip>len){
		return 0; 
	}
	for(long long i=ip;i<=len;i++){
		if(b[i].l<=rr&&b[i].r!=b[i].l){
			continue;
		}
		ans=max(ans,dfs(ans+1,b[i].r,i+1));
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long i,j;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0,ip;
	for(i=1;i<=n;i++){
		ip=a[i];
		if(ip==k){
			ans++;
			//cout<<i<<" "<<i<<"\n";
			len++;
			b[len].l=b[len].r=i;
			maxr=max(maxr,i);
			break;
		}
		for(j=i+1;j<=n;j++){
			ip^=a[j];
			if(ip==k){
				ans++;
				len++;
				b[len].l=i;
				b[len].r=j;
				maxr=max(maxr,j);
				//cout<<i<<" "<<j<<"\n";
				break;
			}
		}
	}
	ans=dfs(0,0,1);
	cout<<ans;
	return 0;
}
/*
4 3
2 1 0 3

4 0
2 1 0 3
*/
