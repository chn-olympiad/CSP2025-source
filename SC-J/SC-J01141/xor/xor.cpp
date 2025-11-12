#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,lst[N],cnt;
long long k,a[N],pre[N];
map<long long,int> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int t=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) pre[i]=a[i];
		else pre[i]=pre[i-1]^a[i];
		if(a[i]==k) lst[i]=i;
		else if(mp[pre[i]^k]!=0)
			lst[i]=mp[pre[i]^k]+1;
		else if((pre[i]^k)==0) lst[i]=1;
		mp[pre[i]]=i;
		if(lst[i]==0) continue;
		if(lst[i]<=t) continue;
		t=i;
		cnt++;
	}
	cout<<cnt;
	return 0;
}