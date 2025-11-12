#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> v;
vector<int> xorv;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int h;
	xorv.push_back(0);
	for(int i=0;i<n;i++){
		scanf("%d",&h);
		v.push_back(h);
		xorv.push_back(xorv[int(xorv.size())-1]^v[int(v.size())-1]);
	}
	int lxor=0,maxs=0;
	for(int i=1;i<=int(xorv.size())-1;i++){
		if((xorv[i]^xorv[lxor])==k){
			maxs++;
			lxor=i;
		}
	}
	cout<<maxs;
	return 0;
}
