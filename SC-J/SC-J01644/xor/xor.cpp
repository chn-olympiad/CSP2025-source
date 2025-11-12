#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
//const int N =
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k,sum=0;
	cin>>n>>k;
	vector<int>a(n+1),b(n+1);
	vector<int>vis;
	vis.push_back(0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) sum++,vis.push_back(i);
		b[i]=a[i]^b[i-1];
	}
	vis.push_back(n+1);
	for(int j=0;j<vis.size()-1;j++){
		int l=vis[j]+1,r=vis[j+1]-1;
		map<long long,bool>viss;
		viss[a[l]]=viss[0]=1;
		for(int i=l+1;i<=r;i++){
			//以i结尾，是否存在满足条件的区间
			int t=b[i]^b[l-1];
			if(viss[t^k]){
				sum++;
				l=i+1;
				viss=map<long long,bool>();
				viss[a[l]]=viss[0]=1;
				i++;
			}else viss[b[i]^b[l-1]]=1;
		}
	}
	cout<<sum;
	return 0;
}
//^k=0