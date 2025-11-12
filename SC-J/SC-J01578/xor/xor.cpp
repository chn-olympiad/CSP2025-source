#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=5e5+5;
ll n,k,a[maxn];
ll qzh[maxn];
bool vis[maxn];
int ans=0;

inline int Xor(int x,int y){
	int a1=min(x,y),a2=max(x,y),a3=0;
	for(int i=0;a1>0 || a2>0;++i){
		int a1_1=a1%2,a2_1=a2%2;
		if(a1_1==a2_1)a3+=(0<<i);
		else a3+=(1<<i);
		a1=a1>>1,a2=a2>>1;
	}
	return a3;
}

inline int Xor_c(int x,int y){
	int a1=min(x,y),a2=max(x,y),a3=0;
	for(int i=0;a1>0 || a2>0;++i){
		int a1_1=a1%2,a2_1=a2%2;
		if(a2_1)a3+=( (!a1_1) << i );
		else a3+=( (a1_1) << i );
		a1=a1>>1,a2=a2>>1;
	}
	return a3;
}

inline bool check(int l,int r){
	for(int i=l;i<=r;++i)if(vis[i])return 0;
	return 1;
} 

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	
	for(int i=1;i<=n;++i)
	if(a[i]==k){
		vis[i]=1,ans++;
	}

	qzh[0]=0;
	for(int i=1;i<=n;++i)qzh[i]=Xor(qzh[i-1],a[i]);
	for(int L=2;L<=n;++L){
		for(int i=L;i<=n;++i){
			if(check(i-L+1,i) && Xor_c(qzh[i],qzh[i-L]) == k){
				ans++;
				for(int st=i-L+1;st<=i;++st)vis[st]=1;
				i=i+L-1;
			}
		}
	}
	
	cout<<ans;
	
	return 0;
}