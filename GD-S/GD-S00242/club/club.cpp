#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
const int N=1e5+114;
int n;
int ans;
int a[N][5];
int ficompare[5];
vector<int>fi[5]; 
int maxfi=0,maxfinum=0;
int diff[N];
void init(){
	memset(ficompare,0,sizeof(ficompare));
	ans=0;
	maxfi=maxfinum=0;
	fi[1].clear();
	fi[2].clear();
	fi[3].clear();
	memset(diff,0,sizeof(diff));
}
void doswap(int maxfi){
	if(maxfi==1){
		return;
	}
	if(maxfi==2){
		swap(ficompare[1],ficompare[2]);
		swap(fi[1],fi[2]);
		for(int i=1;i<=n;i++){
			swap(a[i][1],a[i][2]);
		}
		return;
	}
	if(maxfi==3){
		swap(ficompare[1],ficompare[3]);
		swap(fi[1],fi[3]);
		for(int i=1;i<=n;i++){
			swap(a[i][1],a[i][3]);
		}
		return;
	}
}

void in_and_predo(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int maxn=0,maxj=0;
		for(int j=1;j<=3;j++){
			if(a[i][j]>maxn){
				maxj=j;
				maxn=a[i][j];
			}
		}
		ans+=maxn;
		fi[maxj].push_back(i);
		ficompare[maxj]++;
	}
//	int maxfi=0,maxfinum=0;
	for(int j=1;j<=3;j++){
		if(ficompare[j]>maxfinum){
			maxfi=j;
			maxfinum=ficompare[j];
		}
	}
	doswap(maxfi);
	return;
}
void solve(){
	init();
	in_and_predo();
	if(maxfinum<=n/2){
		cout<<ans<<endl;
		return;
	}
	int t=0;
	for(int x:fi[1]){
		int m,n;
		m=a[x][1];
		n=max(a[x][2],a[x][3]);
		diff[++t]=m-n;
	}
	sort(diff+1,diff+t+1);
	for(int i=1;i<=maxfinum-n/2;i++){
		ans-=diff[i];
	}
	cout<<ans<<endl;
	
	return;
}
signed main(){
	IOS
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
