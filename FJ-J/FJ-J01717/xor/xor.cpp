#include <bits/stdc++.h>
using namespace std;
int xo[500020],edge[500020],f[500020][2],lst[500020];
map <int,vector <int>> bucket;
int check(int n,int k){
	int l=0,r=bucket[k].size()-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(bucket[k][mid]>n) r=mid-1;
		if(bucket[k][mid]<=n) l=mid+1; 
	}if(l>=bucket[k].size()) return -1;
	return bucket[k][l];
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(edge,-1,sizeof(edge));
	int n,k; cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> xo[i]; xo[i]=xo[i]^xo[i-1];
		bucket[xo[i]].push_back(i);
	}//cout << bucket[3].size() << endl;
	for(int i = 0;i < n;i++){
		int t=k^xo[i];
		/*
		for(int j = 0;j < bucket[t].size();j++){
			if(bucket[t][j]>i){edge[i+1]=bucket[t][j];break;}
		}
		*/
		if(bucket[t].size())edge[i+1]=check(i,t);
		//cout << i+1 << ' ' << edge[i+1] << endl;
	}
	for(int i = 1;i <= n;i++){
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		lst[i]=max(lst[i],lst[i-1]);
		if(edge[i]!=-1){
			//cout << i << ' ' << edge[i] << ' ' << lst[i] << endl;
			f[i][1]=max(f[lst[i]][0],f[lst[i]][1])+1;
			lst[edge[i]+1]=max(lst[edge[i]+1],i);
		}
	}cout << max(f[n][1],f[n][0]);
	//2 1 0 3
	//2 3 3 0
	//[2,4]->xo[4]^xo[1]==k
	//lis[i]^x==k
	//lis[i]^k==x
	//xo[i]^xo[i-1]^k==x^
	//AC! RP+=INF;!
	return 0;
}
