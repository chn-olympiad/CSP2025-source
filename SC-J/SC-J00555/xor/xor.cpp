#include<bits/stdc++.h>
using namespace std;
int num[500005]={0},cha[200005]={0};
vector<int> path[2];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	int l=1,r=1,total=num[1];
	while(l<=n&&r<=n){
		if(total==k){
			path[0].push_back(l);
			path[1].push_back(r);
			ans++;
		}
		r++;
		total^=num[r];
		if(r>n){
			l++;
			r=l;
			total=num[l];
		}
	}
	for(int it:path[0]){
		cha[it]++;
		cout<<it<<" ";
	}
	for(int it:path[1]){
		cha[it+1]--;
		cout<<it<<" ";
	}
	for(int i=1;i<=200000;i++){
		cha[i]+=cha[i-1];
		if(cha[i]>1){
			ans-=cha[i]-1;
		}
	}
	cout<<ans;
	return 0;
}