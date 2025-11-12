#include<bits/stdc++.h>
using namespace std;
long long n,k,cnt,ans,a[500005],s[500005];
typedef pair<int,int>pii;
vector<pii> e;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) s[i]=a[i];
		else s[i]=s[i-1]^a[i]; 
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cnt=s[j]^s[i-1];
			if(cnt==k){
				e.push_back({i,j});
			}
		}
	}
	for(int i=0;i<e.size();i++){
		long long cnt1=e[i].first,cnt2=e[i].second,sum=1;
		for(int j=i+1;j<e.size();j++){
			if(e[j].first<cnt2&&e[j].second<cnt2) cnt1=e[j].first,cnt2=e[j].second;
			if(e[j].first>cnt2) sum++,cnt1=e[j].first,cnt2=e[j].second;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	
	return 0;
}
