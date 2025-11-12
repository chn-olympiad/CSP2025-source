#include<bits/stdc++.h>
using namespace std;
const int N=500009;
const int M=1048576+10;
int a[N],pre[N];
bool last[M];
int n,k,ans=0;
int ff(int l,int r){
	return pre[l-1]^pre[r];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	memset(last,false,sizeof(last));
	last[0]=true;
	for(int i=1,x=0,j=1;i<=n;i++){
		x=ff(j,i)^k;
		if(last[x]){
			j=i+1;
			memset(last,false,sizeof(last));
			last[0]=true;
			ans++;
		}
		last[ff(j,i)]=true;
	}
	cout<<ans<<endl;
	return 0;
}
