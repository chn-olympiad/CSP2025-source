#include<bits/stdc++.h>//RP++
using namespace std;//RP++
const int N=500005;//RP++
vector<int> g;//RP++
int a[N],n,k;//RP++
int sum[N];//RP++
int main() {//RP++
	freopen("xor.in","r",stdin);//RP++
	freopen("xor.out","w",stdout);//RP++
	cin>>n>>k;//RP++
	sum[0]=0;//RP++
	int maxn=0;//RP++
	for(int i=1; i<=n; i++) {//RP++
		cin>>a[i];//RP++
		sum[i]=sum[i-1]^a[i];//RP++
		maxn=max(maxn,a[i]);//RP++
	}//RP++
	if(maxn==1) {//RP++
		int cnt=1;//RP++
		for(int i=2; i<=n; i++) {//RP++
			if(a[i]!=a[i-1]) {//RP++
				g.push_back(cnt);//RP++
				cnt=1;//RP++
			}else cnt++;//RP++
		}//RP++
		if(cnt>1) g.push_back(cnt);//RP++
		int ans=0,j=a[1];//RP++
		for(int i=0;i<g.size();i++){//RP++
			if(j==k) ans+=g[i];//RP++
			else ans+=g[i]/2;//RP++
			j^=1;//RP++
		}//RP++
		cout<<ans;//RP++
	}//RP++
	return 0;//RP++
}//RP++
