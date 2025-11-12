#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+4;
int a[maxn],num[maxn];
pair<int,int>q[maxn];
bool cmp(pair<int,int>x,pair<int,int>y){
	return x.second<y.second;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k,ans=0; cin>>n>>k;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) flag=false;
	}
	if(flag and k<=1){
		int cnt1=0,cnt0=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt1++;
			else cnt0++;
		}
		if(k==0) ans=cnt1/2+cnt0;
		else ans=max(cnt1-cnt0,0)+min(cnt1,cnt0);
	}
	else if(flag and k>1){
		return cout<<"0\n",0;
	}
	else{
		memset(num,-1,sizeof(num));
		for(int i=1;i<=n;i++){
			q[i]={n+1,n+1};
			for(int j=1;j<=i;j++){
				if(num[j]==k) continue;
				if(num[j]==-1) num[j]=0;
				num[j]^=a[i];
				if(num[j]==k) q[j]={j,i};
			}
		}
		sort(q+1,q+1+n,cmp);
		int index=1,last=0;
		while(1){
			while(q[index].first<=last) index++;
			if(q[index].first<=n) ans++;
			else break;
			last=q[index].second;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
