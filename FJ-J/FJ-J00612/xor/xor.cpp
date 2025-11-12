#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int m,n;
int s[N],txs[N],st[N];
vector< pair<int,int> > vec;
bool cmp(pair<int,int> a,pair<int,int> b){
	if((a.first-a.second)!=(b.first-b.second)) return (a.first-a.second)>(b.first-b.second);
	return a.first<a.second;
}
int main(){
	//QwQ
	freopen("xor.out","w",stdout);
	freopen("xor.in","r",stdin);
	cin>>n>>m;
	int ans=0;
	bool spe=1,spe2=1;
	int cnt0=0,cnt1=0,cnt21=0,cnt21n=-1;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		txs[i]=txs[i-1]^s[i];
		if(s[i]==1) cnt1++;
		if(s[i]==0) cnt0++;
		if(s[i]==1){
			if(s[i-1]==1&&cnt21n<i-1){
				cnt21++;
				cnt21n=i;
			}
		}
		if(s[i]!=1) spe=0;
		if(s[i]!=1&&s[i]!=0) spe2=0;
	}
	if(!spe){
		for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)if((txs[j]^txs[i-1])==m) vec.push_back({i,j});
		sort(vec.begin(),vec.end(),cmp);
		for(auto t:vec){
			int flag=1;
			for(int i=t.first;i<=t.second;i++) if(st[i]){
				flag=0;
				break;
			}
			if(flag){
				for(int i=t.first;i<=t.second;i++) st[i]=1;
				ans++;
			}
		}
		cout<<ans;
	}else if(!spe2)cout<<(n+1)/2;
	else{
		if(m) cout<<cnt1;
		else{
			cout<<cnt21+cnt0;
		}
	}
	return 0;
}
