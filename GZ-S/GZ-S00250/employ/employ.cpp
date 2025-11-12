//GZ-S00250 毕节七星关东辰实验学校 杜启民 
#include<iostream>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#define ll long long
#define heap priority_heap
using namespace std;

const int N=20;
ll c=998244353 ,m,n,h[N],ans;
string s;

bool bk[N];
ll arr[N];

void f(ll p,ll l){
	bk[p]=1;
	arr[l]=h[p];
	
	if(l==n){
		ll sum=0;
		for(int i=1;i<=n;i++){
			if(sum>=arr[i]||s[i-1]=='0'){
				sum++;
			}
		}if(n-sum>=m){
		/*	for(int i=1;i<=n;i++){
				cout<<arr[i]<<' ';
			}cout<<'\n';*/
			ans++;
			ans%=c;
		}bk[p]=0;
		return;
	}for(int i=1;i<=n;i++){
		if(!bk[i]){
			f(i,l+1);
		}
	}bk[p]=0;
}

inline void solve(){
	
	cin>>n>>m;
	cin>>s;
	
	for(int i=1;i<=n;i++)cin>>h[i];
	
	f(0,0);
	
	cout<<ans;
	
	return;
}

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int T=1;
// 	cin>>T;
	while(T--)solve();
	
	return 0;
}
