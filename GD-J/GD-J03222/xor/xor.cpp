#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=1e5+10,A=(1<<20)+10;
int n,k;
int a;
int lst,xsum;
int ans;
array<vector<int>,A> bct;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	lst=ans=0;
	bct[0].emplace_back(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		xsum^=a;
		if(!bct[xsum^k].empty()){
			int pos=lower_bound(bct[xsum^k].begin(),bct[xsum^k].end(),lst)-bct[xsum^k].begin();
			if(pos!=(int)bct[xsum^k].size()) ans++,lst=i;
		}
		bct[xsum].emplace_back(i);
	}
	cout<<ans;
	return 0;
}
