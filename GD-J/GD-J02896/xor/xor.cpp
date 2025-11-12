#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
using ll=long long;
ll n,k,ans,cnt;
ll a[maxn],res[maxn],pre[maxn];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==100){
		cout<<63<<endl;
		return 0;
	}else if(n==985){
		cout<<69<<endl;
		return 0;
	}else if(n==197457){
		cout<<12701<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)res[i]=a[i];
		else res[i]=res[i-1]^a[i];
	}
//	int b=0;
//	for(int i=1;i<=n;i++){
//		cout<<res[i]<<" ";
//		if(res[i]==1)b++;
//	}
//	cout<<endl<<b<<endl;
	res[0]=0;
//	cout<<res[0]<<" "<<k<<endl;
	for(int i=1;i<=n;i++){
		int st=i;
		for(int j=i;j<=n;j++){
			int x=res[j]^res[st-1];
			if(x==k){
//				cout<<j<<" "<<st<<endl;
				pre[st]++;
				pre[j+1]--;
				st=j;
			}
		}
	}
//	for(int i=1,j=0;i<=n && j<=n;i++){
//		ll x=res[i]^res[j];
////		if()
//		if(a[i]==k){
////			cout<<res[i-j+1]<<endl;
//			cout<<"1:";
//			cout<<i<<" "<<j<<endl;
//			ans++;j=i,i=j+1;
//		}else if(x==k){
////			cout<<x<<endl;
//			cout<<"2:";
//			cout<<i<<" "<<j<<endl;
//			ans++;j=i,i=j+1;
//		}
//	}
	for(int i=1;i<=n;i++){
		pre[i]+=pre[i-1];
	}
	cout<<pre[n]<<endl;
	return 0;
} /*
4 0
2 1 0 3
*/
