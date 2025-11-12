#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=(1<<20)+10;
int n,k,a[500010],q[500010],r[M];
void solveab(){
	int ans=0,l=0;
	if(k==0) for(int i=1;i<=n;i++){
		l^=a[i];
		if(a[i]==0||l==0)ans++,l=0;
	}
	else for(int i=1;i<=n;i++)
		if(a[i]==1)ans++;
	cout<<ans;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool tf=1;
	for(int i=1;i<=n;i++)cin>>a[i],tf&=(a[i]<=1);
	if(tf){//ÌØÊâÐÔÖÊA,B 
		solveab();
		return 0;
	}
	int ans=0,l=-1;
	memset(r,0,sizeof r);
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]^a[i];
		r[q[i-1]]=i;
		if((k^a[i])==0){
			ans++,l=i;
			continue;
		}
		int pos=r[k^q[i]];
		if(l<pos&&(q[pos-1]^q[i])==k)ans++,l=i;
	}
	cout<<ans;
	return 0;
}/*

*/
