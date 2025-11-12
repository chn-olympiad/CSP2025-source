#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e5+5;
int n,k,ans,a[N],pre[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	int nw=0;
	for(int i=1;i<=n;i++){
		
		int w=-1;
		for(int j=nw;j<i;j++){
			int t=pre[i]^pre[j];
			if(t==k){
				w=j;
				break;
			}
		}
		if(w!=-1){
			ans++;
			nw=i;
		}
	}
	cout<<ans;
	return 0;
}
