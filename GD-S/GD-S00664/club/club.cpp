#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=100000;
int n,w[3][MAXN+5],tt[MAXN+5];
void work(){
	cin>>n;
	int tot[3]={0,0,0},ans=0;
	for(int i=1;i<=n;i++){
		cin>>w[0][i]>>w[1][i]>>w[2][i];
		if(w[0][i]>=w[1][i]&&w[0][i]>=w[2][i]) tt[i]=0;
		else if(w[1][i]>=w[0][i]&&w[1][i]>=w[2][i]) tt[i]=1;
		else tt[i]=2;
		ans+=w[tt[i]][i];
		tot[tt[i]]++;
	}
	int cc=-1;
	if(tot[0]*2>n) cc=0;
	else if(tot[1]*2>n) cc=1;
	else if(tot[2]*2>n) cc=2;
	if(cc==-1) cout<<ans<<"\n";
	else{
		priority_queue<int> q;
		for(int i=1;i<=n;i++){
			if(tt[i]==cc){
				int ls=0;
				if(cc==0) ls=max(w[1][i]-w[0][i],w[2][i]-w[0][i]);
				else if(cc==1) ls=max(w[0][i]-w[1][i],w[2][i]-w[1][i]);
				else ls=max(w[0][i]-w[2][i],w[1][i]-w[2][i]);
				q.push(ls);
			}
		}
		int num=tot[cc]-n/2;
		while(num--){
			ans+=q.top();
			q.pop();
		}
		cout<<ans<<"\n";
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--) work();
	return 0;
}
